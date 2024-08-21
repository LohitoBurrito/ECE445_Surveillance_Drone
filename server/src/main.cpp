#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <memory>

#include "../include/commandControl.h"

// Namespace aliases
namespace ip = boost::asio::ip; 
namespace websocket = boost::beast::websocket;
namespace beast = boost::beast;

// Alias for TCP socket
using tcp = ip::tcp;

// Standard library namespaces
using namespace std;


// Main function
int main() {
    boost::asio::io_context ioc;

    shared_ptr<CommandControl> cc = make_shared<CommandControl>();

    thread s1 ([&] () { bootConnection(ioc, 5000, cc); } );
    thread s2 ([&] () { bootConnection(ioc, 5001, cc); } );

    ioc.run();

    s1.join();
    s2.join();

}

void bootConnection(boost::asio::io_context& ioc, unsigned short port, const shared_ptr<CommandControl>& cc) {

    auto const address = ip::make_address("127.0.0.1");

    tcp::acceptor acceptor{ioc, {address, port}}; 

    function<void()> CommandControlLoop = [&] () {
        acceptor.async_accept(
            [&] (beast::error_code ec, tcp::socket socket) {
                if (!ec) {

                    if (port == 5000) {
                        cout << "Connected GUI" << endl;
                        cc -> connectGUI(socket); 
                    } else {
                        cout << "Connected ESP32" << endl;
                        cc -> connectESP32(socket);
                    }

                    CommandControlLoop();

                } else {
                    cerr << "Error: " << ec.message() << endl;
                }
            }
        );
    };

    CommandControlLoop();
}

