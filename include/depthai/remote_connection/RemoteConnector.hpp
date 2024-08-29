#pragma once

#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/util/time_util.h>
#include <memory.h>

#include <depthai/pipeline/Node.hpp>
#include <depthai/utility/ProtoSerializable.hpp>
#include <foxglove/websocket/base64.hpp>
#include <foxglove/websocket/server_factory.hpp>
#include <foxglove/websocket/websocket_notls.hpp>
#include <foxglove/websocket/websocket_server.hpp>
#include <memory>
#include <optional>

static uint64_t nanosecondsSinceEpoch() {
    return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

namespace dai {
class RemoteConnector {
   public:
    // Constructor and Destructor
    explicit RemoteConnector(const std::string& address = "0.0.0.0", uint16_t port = 8765) {
        initServer(address, port);
    }

    ~RemoteConnector() {
        server->stop();
    }

    void addTopic(const std::string& topicName, Node::Output& output, const std::string& paneName) {
        auto outputQueue = output.createOutputQueue();
        // Start a thread to handle the schema extraction and message forwarding
        std::thread([this, topicName, outputQueue, paneName]() {
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

    // TODO
    // add a function for better low level API
    // Subscribe to events
    // Expose the pipeline
   private:
    // Initializes the WebSocket server
    void initServer(const std::string& address, uint16_t port);
    std::unique_ptr<foxglove::ServerInterface<websocketpp::connection_hdl>> server;
};
}  // namespace dai