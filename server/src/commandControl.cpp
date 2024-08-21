#include <commandControl.h>
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <memory>

// Namespace aliases
namespace ip = boost::asio::ip; 
namespace websocket = boost::beast::websocket;

// Alias for TCP socket
using tcp = ip::tcp;

// Standard library namespaces
using namespace std;

CommandControl::CommandControl () {
    CommandControl::errorCodes.error = -1;
    CommandControl::errorCodes.success = 0;
}

void CommandControl::connectESP32 (tcp::socket& socket) {
    esp32Websocket = make_shared<websocket::stream<tcp::socket>>(move(socket));
    esp32Websocket->async_accept (
        beast::bind_front_handler(
            &CommandControl::onAcceptESP32,
            shared_from_this()
        )
    );
}

void CommandControl::connectGUI (tcp::socket& socket) {
    guiWebsocket = make_shared<websocket::stream<tcp::socket>>(move(socket));
    guiWebsocket->async_accept (
        beast::bind_front_handler(
            &CommandControl::onAcceptGUI,
            shared_from_this()
        )
    );
}

void CommandControl::onAcceptESP32(beast::error_code ec) {
    if (ec) {
        std::cerr << "ESP32 accept error: " << ec.message() << std::endl;
        return;
    }
    doRetrieveFrames();
}

void CommandControl::onAcceptGUI(beast::error_code ec) {
    if (ec) {
        std::cerr << "GUI accept error: " << ec.message() << std::endl;
        return;
    }
    doRecieveCommand();
}

// 

void CommandControl::doRetrieveFrames() {
    esp32Websocket->async_read(
        readDataPacketBuffer,
        beast::bind_front_handler(
            &CommandControl::onRetrieveFrames,
            shared_from_this()
        )
    );
}

void CommandControl::onRetrieveFrames(beast::error_code ec, std::size_t bytes_transferred) {
    if (ec) {
        std::cerr << "GUI accept error: " << ec.message() << std::endl;
        return;
    }

    if (bytes_transferred != 0) {
        lock_guard<mutex> lock(dataPacketMutex);
        dataPacketQueue.push(readDataPacketBuffer);
        writeDataPacketBuffer = dataPacketQueue.front();
    }

    doSendCommand();
}

void CommandControl::doSendCommand() {
    esp32Websocket->async_write(
        writeCommandBuffer,
        beast::bind_front_handler(
            &CommandControl::onSendCommand,
            shared_from_this()
        )
    );
}

void CommandControl::onSendCommand(beast::error_code ec, std::size_t bytes_transferred) {
    if (ec) {
        std::cerr << "GUI accept error: " << ec.message() << std::endl;
        return;
    }

    if (bytes_transferred != 0) {
        lock_guard<mutex> lock(commandMutex);
        commandQueue.pop();
        writeCommandBuffer = commandQueue.front();
    }

    doRetrieveFrames();
}

// 

void CommandControl::doRecieveCommand() {

    guiWebsocket->async_read(
        readCommandBuffer,
        beast::bind_front_handler(
            &CommandControl::onRecieveCommand,
            shared_from_this()
        )
    );
}

void CommandControl::onRecieveCommand(beast::error_code ec, std::size_t bytes_transferred) {
    if (ec) {
        std::cerr << "GUI accept error: " << ec.message() << std::endl;
        return;
    }

    if (bytes_transferred != 0) {
        lock_guard<mutex> lock(commandMutex);
        commandQueue.push(readCommandBuffer);
        writeCommandBuffer = commandQueue.front();
    }

    doSendFrames();
}

void CommandControl::doSendFrames() {
    guiWebsocket->async_write(
        writeDataPacketBuffer,
        beast::bind_front_handler(
            &CommandControl::onSendFrames,
            shared_from_this()
        )
    );
}

void CommandControl::onSendFrames(beast::error_code ec, std::size_t bytes_transferred) {
    if (ec) {
        std::cerr << "GUI accept error: " << ec.message() << std::endl;
        return;
    }

    if (bytes_transferred != 0) {
        lock_guard<mutex> lock(dataPacketMutex);
        dataPacketQueue.pop();
        writeDataPacketBuffer = dataPacketQueue.front();   
    }

    doRecieveCommand();
}