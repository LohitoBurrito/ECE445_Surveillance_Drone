
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_context.hpp>
#include <memory>
#include <queue>
#include <vector>
#include <mutex>

// Namespace aliases
namespace ip = boost::asio::ip; 
namespace websocket = boost::beast::websocket;
namespace beast = boost::beast;

// Alias for TCP socket
using tcp = ip::tcp;

// Standard library namespaces
using namespace std;
struct ErrorCodes {
    int error;
    int success;
};

struct DataPackets {
    vector<vector<tuple<int, int, int>>> frame;
    double altitude;
    double yaw;
    double pitch;
    double roll;
};

class CommandControl : enable_shared_from_this<CommandControl> {
    private:
        
        queue<beast::flat_buffer> dataPacketQueue;
        queue<beast::flat_buffer> commandQueue;
        beast::flat_buffer readDataPacketBuffer;
        beast::flat_buffer writeDataPacketBuffer;
        beast::flat_buffer readCommandBuffer;
        beast::flat_buffer writeCommandBuffer;
        
        mutex dataPacketMutex;
        mutex commandMutex;

        ErrorCodes errorCodes;
        shared_ptr<websocket::stream<tcp::socket>> guiWebsocket;
        shared_ptr<websocket::stream<tcp::socket>> esp32Websocket;


    public:
        CommandControl();
        void connectGUI(tcp::socket& socket);
        void connectESP32(tcp::socket& socket);
        void onAcceptGUI(beast::error_code ec);
        void onAcceptESP32(beast::error_code ec);
        void CommandControl::doRecieveCommand();
        void CommandControl::onRecieveCommand(beast::error_code ec, std::size_t bytes_transferred);
        void CommandControl::doSendCommand();
        void CommandControl::onSendCommand(beast::error_code ec, std::size_t bytes_transferred);
        void CommandControl::doRetrieveFrames();
        void CommandControl::onRetrieveFrames(beast::error_code ec, std::size_t bytes_transferred);
        void CommandControl::doSendFrames();
        void CommandControl::onSendFrames(beast::error_code ec, std::size_t bytes_transferred);
};
