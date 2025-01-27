#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <curl/curl.h>
#include <condition_variable>
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

struct DataPacket {
    vector<vector<tuple<int, int, int>>> frame;
    double altitude;
    double yaw;
    double pitch;
    double roll;
    double acceleration;
    double latitude;
    double longitude;
};

struct memory {
    char* response;
    size_t size;
};

struct curlStruct {
    CURL* commandCurl;
    int commandCount;
    string baseUrl;
    string params;
    struct curl_slist *commandHeaders;
};

class CommandControl : public enable_shared_from_this<CommandControl> {
    private:
        tcp::acceptor acceptorReadGUI;
        tcp::acceptor acceptorWriteGUI;

        // Websocket Shared Pointers
        shared_ptr<websocket::stream<tcp::socket>> websocketReadGUI;
        shared_ptr<websocket::stream<tcp::socket>> websocketWriteGUI;

        // HTTP Shared Pointers
        shared_ptr<curlStruct> commandPost;
        shared_ptr<curlStruct> commandDelete;
        shared_ptr<curlStruct> commandGet;

        shared_ptr<curlStruct> sensorGet;
        shared_ptr<curlStruct> sensorDelete;

        net::io_context& ioc;
        beast::flat_buffer bufferReadCommand;
        beast::flat_buffer bufferWriteCommand;
        beast::flat_buffer bufferReadDataPacket;
        beast::flat_buffer bufferWriteDataPacket;

        mutex mutexCommand;
        mutex mutexDataPacket;  

        queue<beast::flat_buffer> queueCommand;
        queue<beast::flat_buffer> queueDataPacket;

        condition_variable conditionCommand;

        string project_id;

    public:
        CommandControl(
            net::ip::address addr, 
            net::io_context& ioc, 
            unsigned short port_read_command,
            unsigned short port_write_data_packet
        );

        ~CommandControl();

        void clearDB(shared_ptr<curlStruct>& getCurl, shared_ptr<curlStruct>& deleteCurl);
        void bootRWCommand();
        void bootRWSensor();
        void connectRWCommand(beast::error_code ec, tcp::socket socket);
        void connectRWSensor(beast::error_code ec, tcp::socket socket);
        void acceptRWCommand(beast::error_code ec);
        void acceptRWSensor(beast::error_code ec);

        void doReadCommandValue();
        void onReadCommandValue(beast::error_code ec, size_t bytes_transferred);
        void doWriteCommandValue();


        void doReadSensorValue();
        void doWriteSensorValue();
        void onWriteSensorValue(beast::error_code ec, size_t bytes_transferred);
};
