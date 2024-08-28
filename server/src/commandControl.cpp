#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <WinSock2.h>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <queue>
#include <vector>
#include <condition_variable>

#include "../include/commandControl.h"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>4

using namespace std;

void pass(string text) {
    cout << "\033[32m" << text << "\033[0m" << endl;
}

void warning(string text) {
    cerr << "\033[33m" << text << "\033[0m" << endl;
}

void error(string text) {
    cerr << "\033[31m" << text << "\033[0m" << endl;
}

CommandControl::CommandControl(
    net::ip::address addr,
    net::io_context& ioc, 
    unsigned short port_read_command,
    unsigned short port_write_command,
    unsigned short port_read_data_packet,
    unsigned short port_write_data_packet
) : ioc(ioc), 
    acceptorReadGUI(ioc, {addr, port_read_command}), 
    acceptorWriteESP32(ioc, {addr, port_write_command}),
    acceptorReadESP32(ioc, {addr, port_read_data_packet}),
    acceptorWriteGUI(ioc, {addr, port_write_data_packet})  {

}

/* -------------------------------------------  Boot Up Code ------------------------------------------- */

void CommandControl::bootReadGUI() {
    pass("[Read Command] ... Starting Boot");
    acceptorReadGUI.async_accept(
        ioc, 
        [self{shared_from_this()}, this] (beast::error_code ec, tcp::socket socket) {
            connectReadGUI(ec, socket);
        }
    );
}

void CommandControl::connectReadGUI(beast::error_code ec, tcp::socket& socket) {
    if (ec) {
        error("[Read Command] ... TCP Connection Error");
        bootReadGUI();
    } else {
        pass("[Read Command] ... TCP Connection Secured");
    }
    websocketReadGUI = make_shared<websocket::stream<tcp::socket>>(move(socket));
    websocketReadGUI->async_accept(
        beast::bind_front_handler(
            &CommandControl::acceptReadGUI,
            shared_from_this()
        )
    );
}

void CommandControl::acceptReadGUI(beast::error_code ec) {
    if (ec) {
        error("[Read Command] ... Websocket Connection Error");
    } else {
        pass("[Read Command] ... Fully Connected Websocket");
        doReadCommandValue();
    }
}

void CommandControl::bootWriteESP32() {
    pass("[Write Command] ... Starting Boot");
    acceptorWriteESP32.async_accept(
        ioc,
        [self{shared_from_this()}, this] (beast::error_code ec, tcp::socket socket) {
            acceptWriteESP32(ec, socket);
        }
    );
}

void CommandControl::acceptWriteESP32(beast::error_code ec, tcp::socket& socket) {
    if (ec) {
        error("[Write Command] ... TCP Connection Error");
        bootWriteESP32();
    } else {
        pass("[Write Command] ... TCP Connection Secured");
        socketWriteESP32 = make_shared<tcp::socket>(move(socket));
        doWriteCommandValue();
    }
}

void CommandControl::bootReadESP32() {

}

void CommandControl::connectReadESP32(beast::error_code ec, tcp::socket& socket) {

}

void CommandControl::acceptReadESP32(beast::error_code ec) {

}

void CommandControl::bootWriteGUI() {

}

void CommandControl::connectWriteGUI(beast::error_code ec, tcp::socket& socket) {

} 

void CommandControl::acceptWriteGUI(beast::error_code ec) {

}

/* -------------------------------------------  Data Communication Code ------------------------------------------- */

void CommandControl::doReadCommandValue() {
    websocketReadGUI->async_read(
        bufferReadCommand,
        beast::bind_front_handler(
            &CommandControl::onReadCommandValue,
            shared_from_this()
        )
    );
}

void CommandControl::onReadCommandValue(beast::error_code ec, size_t bytes_transferred) {
    if (ec) {
        error("[Read Command] ... Read Command Error");
    } else if (bytes_transferred == 0) {
        warning("[Read Command] ... Zero Bytes Read");
        doReadCommandValue();
    } else {
        pass("[Read Command] ... " + to_string(bytes_transferred) + " Bytes Read");
        {
            lock_guard<mutex> lock(mutexCommand);
            queueCommand.push(bufferReadCommand);
        }
        conditionCommand.notify_one();
        bufferReadCommand.clear();
        doReadCommandValue();
    }
}

void CommandControl::doWriteCommandValue() {
    socketWriteESP32->async_write_some(
        bufferWriteCommand.data(),
        beast::bind_front_handler(
            &CommandControl::onWriteCommandValue,
            shared_from_this()
        )
    );
}

void CommandControl::onWriteCommandValue(beast::error_code ec, size_t bytes_transferred) {
    if (ec) {
        error("[Write Command] ... Write Command Error");
    } else if (bytes_transferred == 0) {
        // warning("[Write Command] ... Zero Bytes Written");
    } else {
        pass("[Write Command] ... " + to_string(bytes_transferred) + " Bytes Written");
    }
    {
        lock_guard<mutex> lock(mutexCommand);

        bufferWriteCommand.clear();
        if (!queueCommand.empty()) {
            bufferWriteCommand = queueCommand.front();
            queueCommand.pop();            
        }
    }
    doWriteCommandValue();
}

void CommandControl::doWriteDataPacketValue() {

}

void CommandControl::onWriteDataPacketValue(beast::error_code ec, size_t bytes_transferred) {

}

void CommandControl::doReadDataPacketValue() {

}

void CommandControl::onReadDataPacketValue(beast::error_code ec, size_t bytes_transferred) {

}