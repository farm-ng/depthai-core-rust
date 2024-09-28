#include "depthai/remote_connection/RemoteConnector.hpp"

#include <iostream>
#include <websocketpp/common/connection_hdl.hpp>

#include "foxglove/websocket/common.hpp"
#include "utility/Resources.hpp"

namespace dai {

inline static uint64_t nanosecondsSinceEpoch() {
    return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

RemoteConnector::RemoteConnector(const std::string& address, uint16_t port) {
    initWebsocketServer(address, port);
    initHttpServer(address, 8000);

    // Expose services
    exposeKeyPressedService();
    exposeTopicGroupsService();
}

RemoteConnector::~RemoteConnector() {
    server->stop();
    httpServer->stop();
    httpServerThread->join();
}

int RemoteConnector::waitKey(int delay_ms) {
    // Implemented based on opencv's waitKey method
    // https://docs.opencv.org/4.x/d7/dfc/group__highgui.html#ga5628525ad33f52eab17feebcfba38bd7

    constexpr int NEUTRAL_VALUE = -1;

    std::unique_lock<std::mutex> lock(keyMutex);
    int ret = keyPressed;
    keyPressed = NEUTRAL_VALUE;

    // If key has been pressed already, just return
    if(ret != NEUTRAL_VALUE) {
        return ret;
    }

    // Wait indefinitely if delay_ms is non-positive
    if(delay_ms <= 0) {
        keyCv.wait(lock);
    } else {
        keyCv.wait_for(lock, std::chrono::milliseconds(delay_ms));
    }

    ret = keyPressed;
    keyPressed = NEUTRAL_VALUE;
    return ret;
}

void RemoteConnector::keyPressedCallback(int key) {
    std::unique_lock<std::mutex> lock(keyMutex);
    keyPressed = key;
    keyCv.notify_all();
}

void RemoteConnector::initWebsocketServer(const std::string& address, uint16_t port) {
    // Create the WebSocket server with a simple log handler
    const auto logHandler = [](foxglove::WebSocketLogLevel, const char* msg) { std::cout << msg << std::endl; };
    foxglove::ServerOptions serverOptions;
    serverOptions.sendBufferLimitBytes = 100 * 1024 * 1024;  // 100 MB
    serverOptions.capabilities.emplace_back("services");
    serverOptions.supportedEncodings.emplace_back("json");
    // Instantiate the server using the factory
    server = foxglove::ServerFactory::createServer<websocketpp::connection_hdl>("DepthAI RemoteConnector", logHandler, serverOptions);

    // Add handlers for the server
    foxglove::ServerHandlers<websocketpp::connection_hdl> hdlrs;
    hdlrs.subscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle clientHandle) {
        const auto clientStr = server->remoteEndpointString(clientHandle);
        std::cout << "Client " << clientStr << " subscribed to " << chanId << std::endl;
    };
    hdlrs.unsubscribeHandler = [&](foxglove::ChannelId chanId, foxglove::ConnHandle clientHandle) {
        const auto clientStr = server->remoteEndpointString(clientHandle);
        std::cout << "Client " << clientStr << " unsubscribed from " << chanId << std::endl;
    };

    hdlrs.serviceRequestHandler = [&](const foxglove::ServiceRequest& request, foxglove::ConnHandle clientHandle) {
        std::cout << "Received service request from client " << server->remoteEndpointString(clientHandle) << std::endl;
        // Check that the service handler is registered
        auto it = serviceMap.find(request.serviceId);
        if(it == serviceMap.end()) {
            server->sendServiceFailure(clientHandle, request.serviceId, request.callId, "Service not found");
            return;
        }
        // Call the service handler
        auto response = it->second(request);
        response.callId = request.callId;
        response.serviceId = request.serviceId;
        server->sendServiceResponse(clientHandle, response);
    };

    server->setHandlers(std::move(hdlrs));
    // Start the server at the specified address and port
    try {
        server->start(address, port);
        std::cout << "Server started at " << address << ":" << port << std::endl;
    } catch(const std::exception& ex) {
        std::cerr << "Failed to start server: " << ex.what() << std::endl;
    }
}

void RemoteConnector::addTopic(const std::string& topicName, Node::Output& output, const std::string& group) {
    auto outputQueue = output.createOutputQueue();
    // Start a thread to handle the schema extraction and message forwarding
    std::thread([this, topicName, outputQueue, group]() {
        bool isRunning = true;
        // Wait for the first message to extract schema
        auto firstMessage = outputQueue->get();
        if(!firstMessage) {
            std::cerr << "No message received from the output for topic: " << topicName << std::endl;
            return;
        }

        auto serializableMessage = std::dynamic_pointer_cast<utility::ProtoSerializable>(firstMessage);
        if(!serializableMessage) {
            std::cerr << "First message is not a ProtoSerializable message for topic: " << topicName << std::endl;
            return;
        }
        // Assuming the first message is a protobuf message
        const auto descriptor = serializableMessage->serializeSchema();

        // Add the topic to the server
        auto channelId = server->addChannels({{.topic = topicName,
                                               .encoding = "protobuf",
                                               .schemaName = descriptor.schemaName,
                                               .schema = foxglove::base64Encode(descriptor.schema),
                                               .schemaEncoding = std::nullopt}})[0];

        // Store the group information
        if(!group.empty()) {
            if(topicGroups.find(topicName) != topicGroups.end()) {
                std::cerr << "Topic named " << topicName << "is already present" << std::endl;
                return;
            }
            topicGroups[group] = topicName;
        }

        // Start the message forwarding loop
        while(isRunning) {
            std::shared_ptr<ADatatype> message;
            try {
                message = outputQueue->get();
            } catch(const dai::MessageQueue::QueueException& ex) {
                std::cout << "Error while getting message from output queue for topic: " << topicName << std::endl;
                isRunning = false;
                continue;
            } catch(const std::exception& ex) {
                std::cerr << "Error while getting message from output queue for topic: " << topicName << std::endl;
                isRunning = false;
                continue;
            }
            if(!message) continue;

            auto serializableMessage = std::dynamic_pointer_cast<utility::ProtoSerializable>(message);
            if(!serializableMessage) {
                std::cerr << "Message is not a ProtoSerializable message for topic: " << topicName << std::endl;
                continue;
            }

            auto serializedMsg = serializableMessage->serializeProto();
            server->broadcastMessage(channelId, nanosecondsSinceEpoch(), static_cast<const uint8_t*>(serializedMsg.data()), serializedMsg.size());
        }
    }).detach();  // Detach the thread to run independently
}

void RemoteConnector::registerPipeline(const Pipeline& pipeline) {
    exposePipelineService(pipeline);
}

std::string getMimeType(const std::string& path) {
    static std::map<std::string, std::string> mimeTypes = {{".html", "text/html"},
                                                           {".htm", "text/html"},
                                                           {".css", "text/css"},
                                                           {".js", "application/javascript"},
                                                           {".png", "image/png"},
                                                           {".jpg", "image/jpeg"},
                                                           {".jpeg", "image/jpeg"},
                                                           {".gif", "image/gif"},
                                                           {".svg", "image/svg+xml"},
                                                           {".json", "application/json"},
                                                           {".txt", "text/plain"}};
    auto ext = path.substr(path.find_last_of("."));
    auto it = mimeTypes.find(ext);
    if(it != mimeTypes.end()) {
        return it->second;
    }
    return "application/octet-stream";  // Default binary type if no match
};

void RemoteConnector::initHttpServer(const std::string& address, uint16_t port) {
    auto visualizerFs = Resources::getInstance().getEmbeddedVisualizer();
    httpServer = std::make_unique<httplib::Server>();
    // httpServer->set_mount_point("/", "/home/matevz/Downloads/viewer-fe-2");
    httpServer->Get("/(.*)", [visualizerFs](const httplib::Request& req, httplib::Response& res) {
        std::string requestedPath = req.matches[1];

        if(requestedPath.empty() || requestedPath == "/") {
            requestedPath = "index.html";  // Default file
        }
        requestedPath = "index/" + requestedPath;
        auto fileData = visualizerFs.getFile(requestedPath);
        if(fileData) {
            res.set_content(std::string(fileData.value().begin(), fileData.value().end()), getMimeType(requestedPath));
        } else {
            res.status = 404;
            res.set_content("File not found", "text/plain");
        }
    });
    std::cout << "To connect to the DepthAI visualizer, open http://localhost:" << port << " in your browser" << std::endl;
    std::cout << "In case of a different client, replace 'localhost' with the correct hostname" << std::endl;
    // Run the server in a separate thread
    httpServerThread = std::make_unique<std::thread>([this, address, port]() { httpServer->listen(address, port); });
}

void RemoteConnector::exposeTopicGroupsService() {
    std::vector<foxglove::ServiceWithoutId> services;
    auto topicGroupsService = foxglove::ServiceWithoutId();
    topicGroupsService.name = "topicGroups";
    auto request = foxglove::ServiceRequestDefinition();
    request.schemaName = "topicGroups";
    request.schema = "";
    request.encoding = "json";
    topicGroupsService.request = request;
    topicGroupsService.response = request;
    topicGroupsService.type = "json";
    services.push_back(topicGroupsService);
    auto ids = server->addServices(services);
    assert(ids.size() == 1);
    auto id = ids[0];

    // Add the handler
    serviceMap[id] = [this](foxglove::ServiceResponse request) {
        (void)request;  // Nothing to do with the request
        auto response = foxglove::ServiceResponse();
        nlohmann::json topicGroupsJson = this->topicGroups;
        std::string serializedTopicGroups = topicGroupsJson.dump();
        response.data = std::vector<uint8_t>(serializedTopicGroups.begin(), serializedTopicGroups.end());
        return response;
    };
}

void RemoteConnector::exposeKeyPressedService() {
    std::string serviceName = "keyPressed";
    foxglove::ServiceWithoutId service;
    service.name = serviceName;
    service.type = "json";

    foxglove::ServiceRequestDefinition requestDef;
    requestDef.schemaName = serviceName + "Request";
    requestDef.encoding = "json";
    service.request = requestDef;

    foxglove::ServiceRequestDefinition responseDef;
    responseDef.schemaName = serviceName + "Response";
    responseDef.encoding = "json";
    service.response = responseDef;

    auto ids = server->addServices({service});
    assert(ids.size() == 1);
    auto id = ids[0];
    serviceMap[id] = [this](foxglove::ServiceResponse request) {
        std::string strInt(request.data.begin(), request.data.end());
        int keyPressed = std::stoi(strInt);
        this->keyPressedCallback(keyPressed);
        return foxglove::ServiceResponse{};
    };
}

void RemoteConnector::exposePipelineService(const Pipeline& pipeline) {
    // Add the service
    std::vector<foxglove::ServiceWithoutId> services;
    auto pipelineService = foxglove::ServiceWithoutId();
    pipelineService.name = "pipelineSchema";
    auto request = foxglove::ServiceRequestDefinition();
    request.schemaName = "pipelineSchema";
    request.schema = "";
    request.encoding = "json";
    pipelineService.request = request;
    pipelineService.response = request;
    pipelineService.type = "json";
    services.push_back(pipelineService);
    auto ids = server->addServices(services);
    assert(ids.size() == 1);
    auto id = ids[0];

    // Add the handler
    auto serializedPipeline = pipeline.serializeToJson();
    auto serializedPipelineStr = serializedPipeline.dump();
    serviceMap[id] = [serializedPipelineStr](foxglove::ServiceResponse request) {
        (void)request;  // Nothing to do with the request
        auto response = foxglove::ServiceResponse();
        response.data = std::vector<uint8_t>(serializedPipelineStr.begin(), serializedPipelineStr.end());
        return response;
    };
}

}  // namespace dai