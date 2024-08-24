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

    if (argc != 4) {
        cerr << "Missing Arguments" << endl;
        return EXIT_FAILURE;
    }

    auto const addr = net::ip::make_address(argv[1]);
    auto const port_esp32 = static_cast<unsigned short>(atoi(argv[2]));
    auto const port_gui = static_cast<unsigned short>(atoi(argv[3]));

    net::io_context ioc {};

    shared_ptr<CommandControl> cc = make_shared<CommandControl>(addr, ioc, port_esp32, port_gui);
    
    thread thread_gui(&CommandControl::bootGUI, cc);
    thread thread_esp32(&CommandControl::bootESP32, cc);
    thread_gui.join();
    thread_esp32.join();

    ioc.run();

    return EXIT_SUCCESS;

}