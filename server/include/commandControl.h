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

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>4

using namespace std;

struct DataPackets {
    vector<vector<tuple<int, int, int>>> frame;
    double altitude;
    double yaw;
    double pitch;
    double roll;
};

class CommandControl : public enable_shared_from_this<CommandControl> {
    private:

        tcp::acceptor acceptorESP32;
        shared_ptr<websocket::stream<tcp::socket>> websocketESP32;
        tcp::acceptor acceptorGUI;
        shared_ptr<websocket::stream<tcp::socket>> websocketGUI;

        net::io_context& ioc;
        beast::flat_buffer bufferCommand;
        beast::flat_buffer bufferDataPacket;

    public:
        CommandControl(net::ip::address addr, net::io_context& ioc, unsigned short port_esp32, unsigned short port_gui);
        void bootESP32();
        void connectESP32(beast::error_code ec, tcp::socket& socket); 
        void acceptESP32(beast::error_code ec);
        void bootGUI();
        void connectGUI(beast::error_code ec, tcp::socket& socket); 
        void acceptGUI(beast::error_code ec);
        
};
