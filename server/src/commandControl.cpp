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
    unsigned short port_esp32,
    unsigned short port_gui
) : ioc(ioc), acceptorESP32(ioc, {addr, port_esp32}), acceptorGUI(ioc, {addr, port_gui}) {}

void CommandControl::bootESP32() {
    pass("[ESP32] ... Starting Boot");
    acceptorESP32.async_accept(
        ioc,
        [self{shared_from_this()}, this] (beast::error_code ec, tcp::socket socket) {
            connectESP32(ec, socket);
        }
    );
}

void CommandControl::connectESP32(beast::error_code ec, tcp::socket& socket) {
    if (ec) {
        error("[ESP32] ... TCP Connection Error");
        bootESP32();
    } else {
        pass("[ESP32] ... TCP Connection Secured");
    }
    websocketESP32 = make_shared<websocket::stream<tcp::socket>>(move(socket));
    websocketESP32->async_accept(
        beast::bind_front_handler(
            &CommandControl::acceptESP32,
            shared_from_this()
        )
    );
}

void CommandControl::acceptESP32(beast::error_code ec) {
    if (ec) {
        error("[ESP32] ... Websocket Connection Error");
    } else {
        pass("[ESP32] ... Fully Connected Websocket");
    }
}

void CommandControl::bootGUI() {
    pass("[GUI] ... Starting Boot");
    acceptorGUI.async_accept(
        ioc,
        [self{shared_from_this()}, this] (beast::error_code ec, tcp::socket socket) {
            connectGUI(ec, socket);
        }
    );
}

void CommandControl::connectGUI(beast::error_code ec, tcp::socket& socket) {
    if (ec) {
        error("[GUI] ... TCP Connection Error");
        bootESP32();
    } else {
        pass("[GUI] ... TCP Connection Secured");
    }
    websocketGUI = make_shared<websocket::stream<tcp::socket>>(move(socket));
    websocketGUI->async_accept(
        beast::bind_front_handler(
            &CommandControl::acceptGUI,
            shared_from_this()
        )
    );
}

void CommandControl::acceptGUI(beast::error_code ec) {
    if (ec) {
        error("[GUI] ... Websocket Connection Error");
    } else {
        pass("[GUI] ... Fully Connected Websocket");
    }
}

