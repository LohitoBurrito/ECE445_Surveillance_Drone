#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <queue>
#include <vector>

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
    acceptorReadCommand(ioc, {addr, port_read_command}), 
    acceptorWriteCommand(ioc, {addr, port_write_command}),
    acceptorReadDataPacket(ioc, {addr, port_read_data_packet}),
    acceptorWriteDataPacket(ioc, {addr, port_write_data_packet})  {

}

/* -------------------------------------------  Boot Up Code ------------------------------------------- */

void CommandControl::bootReadCommand() {
    pass("[Read Command] ... Starting Boot");
    acceptorReadCommand.async_accept(
        ioc,
        [self{shared_from_this()}, this] (beast::error_code ec, tcp::socket socket) {
            connectReadCommand(ec, socket);
        }
    );
}

void CommandControl::connectReadCommand(beast::error_code ec, tcp::socket& socket) {
    if (ec) {
        error("[Read Command] ... TCP Connection Error");
        bootReadCommand();
    } else {
        pass("[Read Command] ... TCP Connection Secured");
    }
    websocketReadCommand = make_shared<websocket::stream<tcp::socket>>(move(socket));
    websocketReadCommand->async_accept(
        beast::bind_front_handler(
            &CommandControl::acceptReadCommand,
            shared_from_this()
        )
    );
}

void CommandControl::acceptReadCommand(beast::error_code ec) {
    if (ec) {
        error("[Read Command] ... Websocket Connection Error");
    } else {
        pass("[Read Command] ... Fully Connected Websocket");
        doReadCommandValue();
    }
}

void CommandControl::bootWriteCommand() {
    pass("[Write Command] ... Starting Boot");
    acceptorWriteCommand.async_accept(
        ioc,
        [self{shared_from_this()}, this] (beast::error_code ec, tcp::socket socket) {
            connectWriteCommand(ec, socket);
        }
    );
}

void CommandControl::connectWriteCommand(beast::error_code ec, tcp::socket& socket) {
    if (ec) {
        error("[Write Command] ... TCP Connection Error");
        bootWriteCommand();
    } else {
        pass("[Write Command] ... TCP Connection Secured");
    }
    websocketWriteCommand = make_shared<websocket::stream<tcp::socket>>(move(socket));
    websocketWriteCommand->async_accept(
        beast::bind_front_handler(
            &CommandControl::acceptWriteCommand,
            shared_from_this()
        )
    );
}

void CommandControl::acceptWriteCommand(beast::error_code ec) {
    if (ec) {
        error("[Write Command] ... Websocket Connection Error");
        return;
    } else {
        pass("[Write Command] ... Fully Connected Websocket");
        doWriteCommandValue();
    }
}

/* -------------------------------------------  Data Communication Code ------------------------------------------- */

void CommandControl::doReadCommandValue() {
    websocketReadCommand->async_read(
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
        {
            lock_guard<mutex> lock(mutexCommand);
            queueCommand.push(bufferReadCommand);
        }
        bufferReadCommand.clear();
        doReadCommandValue();
    }
}

void CommandControl::doWriteCommandValue() {
    websocketWriteCommand->async_write(
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
        warning("[Write Command] ... Zero Bytes Written");
    } else {
        this_thread::sleep_for(chrono::milliseconds(1000));
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