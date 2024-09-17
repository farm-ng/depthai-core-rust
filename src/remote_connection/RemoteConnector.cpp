#include "depthai/remote_connection/RemoteConnector.hpp"

#include <iostream>
#include <websocketpp/common/connection_hdl.hpp>
namespace dai {
void RemoteConnector::initWebsocketServer(const std::string& address, uint16_t port) {
    // Create the WebSocket server with a simple log handler
    const auto logHandler = [](foxglove::WebSocketLogLevel, const char* msg) { std::cout << msg << std::endl; };
    foxglove::ServerOptions serverOptions;
    serverOptions.sendBufferLimitBytes = 100 * 1024 * 1024;  // 50 MB

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

    server->setHandlers(std::move(hdlrs));
    // Start the server at the specified address and port
    try {
        server->start(address, port);
        std::cout << "Server started at " << address << ":" << port << std::endl;
    } catch(const std::exception& ex) {
        std::cerr << "Failed to start server: " << ex.what() << std::endl;
    }
}

void RemoteConnector::initHttpServer(const std::string& address, uint16_t port) {
    httpServer = std::make_unique<httplib::Server>();
    httpServer->set_mount_point("/", "/home/matevz/Downloads/viewer-fe-2");
    std::cout << "Starting HTTP server at " << address << ":" << port << std::endl;
    // Run the server in a separate thread
    httpServerThread = std::make_unique<std::thread>([this, address, port]() {
        httpServer->listen(address.c_str(), port);
    });
}
}  // namespace dai
