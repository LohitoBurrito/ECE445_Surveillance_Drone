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
#include <vector>

#include "../include/commandControl.h"

namespace beast = boost::beast;         
namespace http = beast::http;            
namespace websocket = beast::websocket;  
namespace net = boost::asio;             
using tcp = boost::asio::ip::tcp;       

using namespace std;

// Main function
int main(int argc, char* argv[]) {

    if (argc != 6) {
        cerr << "Missing Arguments" << endl;
        return EXIT_FAILURE;
    }

    auto const addr = net::ip::make_address(argv[1]);
    auto const port_read_command = static_cast<unsigned short>(atoi(argv[2]));
    auto const port_write_command = static_cast<unsigned short>(atoi(argv[3]));
    auto const port_readDataPacket = static_cast<unsigned short>(atoi(argv[4]));
    auto const port_writeDataPacket = static_cast<unsigned short>(atoi(argv[5]));

    net::io_context ioc {};

    shared_ptr<CommandControl> cc = make_shared<CommandControl>(
        addr, 
        ioc, 
        port_read_command, 
        port_write_command,
        port_readDataPacket,
        port_writeDataPacket
    );
    
    thread thread_read_command(&CommandControl::bootReadCommand, cc);
    thread thread_write_command(&CommandControl::bootWriteCommand, cc);
    // thread thread_read_data_packet(&CommandControl::bootReadDataPacket, cc);
    // thread thread_write_data_packet(&CommandControl::bootWriteDataPacket, cc);
    
    thread_read_command.join();
    thread_write_command.join();
    // thread_read_data_packet.join();
    // thread_write_data_packet.join();

    ioc.run();

    return EXIT_SUCCESS;

}