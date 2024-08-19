#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <iostream>
#include <string>
#include <thread>

namespace ip = boost::asio::ip; // namespace with multiple types and functions under it
using tcp = ip::tcp; // type tcp

using namespace std;

// SOURCE: https://www.youtube.com/watch?v=3elKoMMuJBA
// SOURCE: https://www.youtube.com/watch?v=ZSefPfZqxpo&t=1976s

int main() {
    
    // Port and Address
    auto const address = ip::make_address("127.0.0.1");
    unsigned short const port = 5000;

    // Used to keep track of all of the tasks and makes sure everything gets done
    boost::asio::io_context ioc{1};

    // The acceptor accepts incoming connections
    tcp::acceptor acceptor{ioc, {address, port}};

    while (1) {
        // Instantiate a Socket
        tcp::socket socket{ioc};

        // Wait for an incoming connection
        acceptor.accept(socket);

        // A Connection got accepted
        cout << "socket accepted" << endl;
    }

}