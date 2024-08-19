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

// Main function
int main() {
    // Address and port
    auto const address = ip::make_address("127.0.0.1");
    unsigned short port = 5000;

    // IO context for managing asynchronous operations
    boost::asio::io_context ioc{1};

    // Acceptor for incoming connections
    tcp::acceptor acceptor{ioc, {address, port}};

    while (true) {
        // Instantiate a socket to handle incoming connections
        tcp::socket socket{ioc};

        // Accept an incoming connection
        acceptor.accept(socket);

        // Log that a connection has been accepted
        cout << "Socket accepted" << endl;
    
        // Create and detach a thread to handle the WebSocket connection
        std::thread{[socket = std::move(socket)]() mutable {
            try {
                // Instantiate a WebSocket stream
                websocket::stream<tcp::socket> ws {std::move(socket)};

                // Accept the WebSocket handshake
                ws.accept();

                // Buffer for reading incoming messages
                boost::beast::flat_buffer buffer;

                while (true) {
                    // Read a message from the WebSocket
                    ws.read(buffer);

                    // Convert the buffer to a string and output it
                    auto output = boost::beast::buffers_to_string(buffer.data());
                    cout << output << endl;

                    // Echo the message back to the client
                    ws.write(buffer.data());

                    // Clear the buffer for the next message
                    buffer.clear();
                }
            } catch (boost::beast::system_error const& e) {
                if (e.code() != boost::beast::websocket::error::closed) {
                    cerr << "Error: " << e.what() << endl;
                } else {
                    cout << "Socked Closed" << endl;
                }
            }
        }}.detach();
    }
}
