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
#include <condition_variable>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>4

using namespace std;

struct DataPacket {
    vector<vector<tuple<int, int, int>>> frame;
    double altitude;
    double yaw;
    double pitch;
    double roll;
};

class CommandControl : public enable_shared_from_this<CommandControl> {
    private:
        tcp::acceptor acceptorReadGUI;
        tcp::acceptor acceptorWriteESP32;
        tcp::acceptor acceptorReadESP32;
        tcp::acceptor acceptorWriteGUI;

        shared_ptr<websocket::stream<tcp::socket>> websocketReadGUI;
        shared_ptr<websocket::stream<tcp::socket>> websocketWriteGUI;

        shared_ptr<tcp::socket> socketReadESP32;
        shared_ptr<tcp::socket> socketWriteESP32;


        net::io_context& ioc;
        beast::flat_buffer bufferReadCommand;
        beast::flat_buffer bufferWriteCommand;
        beast::flat_buffer bufferReadDataPacket;
        beast::flat_buffer bufferWriteDataPacket;

        mutex mutexCommand;
        mutex mutexDataPacket;  

        queue<beast::flat_buffer> queueCommand;
        queue<DataPacket> queueDataPacket;

        condition_variable conditionCommand;

    public:
        CommandControl(
            net::ip::address addr, 
            net::io_context& ioc, 
            unsigned short port_read_command,
            unsigned short port_write_command,
            unsigned short port_read_data_packet,
            unsigned short port_write_data_packet
        );

        void bootReadGUI();
        void connectReadGUI(beast::error_code ec, tcp::socket& socket); 
        void acceptReadGUI(beast::error_code ec);

        void bootWriteESP32();
        void acceptWriteESP32(beast::error_code ec, tcp::socket& socket); 
        
        void bootReadESP32();
        void connectReadESP32(beast::error_code ec, tcp::socket& socket); 
        void acceptReadESP32(beast::error_code ec);

        void bootWriteGUI();
        void connectWriteGUI(beast::error_code ec, tcp::socket& socket); 
        void acceptWriteGUI(beast::error_code ec);

        void doReadCommandValue();
        void onReadCommandValue(beast::error_code ec, size_t bytes_transferred);
        void doWriteCommandValue();
        void onWriteCommandValue(beast::error_code ec, size_t bytes_transferred);

        void doWriteDataPacketValue();
        void onWriteDataPacketValue(beast::error_code ec, size_t bytes_transferred);
        void doReadDataPacketValue();
        void onReadDataPacketValue(beast::error_code ec, size_t bytes_transferred);
};
