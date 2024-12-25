#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/dispatch.hpp>
#include <boost/asio/strand.hpp>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <condition_variable>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <thread>
#include <queue>
#include <vector>
#include <functional>
#include <typeinfo>
#include <chrono>

#include "../include/commandControl.h"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>4
using json = nlohmann::json;            // from <nlohmann/json.hpp>

using namespace std;

/* -------------------------------------------  Loggers  ------------------------------------------- */

void pass(string text) {
    cout << "\033[32m" << text << "\033[0m" << endl;
}

void warning(string text) {
    cerr << "\033[33m" << text << "\033[0m" << endl;
}

void error(string text) {
    cerr << "\033[31m" << text << "\033[0m" << endl;
}

/* -------------------------------------------  Command Control Constructor Code  ------------------------------------------- */

static size_t clearDBCallback(char* data, size_t size, size_t nmemb, void *userp) {
    size_t actualSize = size * nmemb;
    ((string*)userp)->append((char*)data, actualSize);
    return actualSize;
}

void CommandControl::clearDB(shared_ptr<curlStruct>& getCurl, shared_ptr<curlStruct>& deleteCurl) {
    string storage;
    
    curl_easy_setopt(getCurl->commandCurl, CURLOPT_URL, getCurl->baseUrl.data());
    curl_easy_setopt(getCurl->commandCurl, CURLOPT_WRITEFUNCTION, clearDBCallback);
    curl_easy_setopt(getCurl->commandCurl, CURLOPT_WRITEDATA, &storage);

    CURLcode res = curl_easy_perform(getCurl->commandCurl);
    if (res != CURLE_OK) {
        error("[Clear Data] ... GET Request Failed: ");
        cerr << curl_easy_strerror(res) << endl;
    } else {
        pass("[Clear Data] ... GET Request Succeeded");
    }

    json storageJSON = json::parse(storage);
    bool storageCleared = true;

    storage.clear();
    curl_easy_setopt(deleteCurl->commandCurl, CURLOPT_CUSTOMREQUEST, "DELETE");
    curl_easy_setopt(deleteCurl->commandCurl, CURLOPT_WRITEFUNCTION, clearDBCallback);
    curl_easy_setopt(deleteCurl->commandCurl, CURLOPT_WRITEDATA, &storage);


    for (const auto& badData : storageJSON["documents"]) {

        string deleteURL = deleteCurl->baseUrl + static_cast<string>(badData["name"]);

        curl_easy_setopt(deleteCurl->commandCurl, CURLOPT_URL, deleteURL.data());
        res = curl_easy_perform(deleteCurl->commandCurl);
        if (res != CURLE_OK) {
            storageCleared = false;
            error("[Clear Data] ... DELETE Request Failed: ");
            cerr << curl_easy_strerror(res) << endl;
        }
    }

    if (storageCleared) {
        pass("[Clear Data] ... DELETE Request Succeeded");
    }
}

CommandControl::CommandControl(
    net::ip::address addr,
    net::io_context& ioc, 
    unsigned short port_read_command,
    unsigned short port_write_data_packet
) : ioc(ioc), 
    acceptorReadGUI(ioc, {addr, port_read_command}),
    acceptorWriteGUI(ioc, {addr, port_write_data_packet})  {

    project_id = "ece445-early-response-dr-9140f";

    function<void(shared_ptr<curlStruct>&, string)> setupCurl = [] (shared_ptr<curlStruct>& curl, string url) {

        curl = make_shared<curlStruct>();
        curl->baseUrl = url;
        curl->commandCurl = curl_easy_init();
        curl->commandHeaders = curl_slist_append(nullptr, "Content-Type: application/json");
        if (!curl->commandCurl) {
            error("[Curl] ... Curl Setup Failed");
            return;
        }
        curl_easy_setopt(curl->commandCurl, CURLOPT_HTTPHEADER, curl->commandHeaders);
        curl_easy_setopt(curl->commandCurl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl->commandCurl, CURLOPT_SSL_VERIFYHOST, 0L);

    };

    setupCurl(commandGet, "https://firestore.googleapis.com/v1/projects/ece445-early-response-dr-9140f/databases/(default)/documents/Commands");
    setupCurl(commandDelete, "https://firestore.googleapis.com/v1/");
    setupCurl(sensorGet, "https://firestore.googleapis.com/v1/projects/ece445-early-response-dr-9140f/databases/(default)/documents/SensorData");
    setupCurl(sensorDelete, "https://firestore.googleapis.com/v1/projects/ece445-early-response-dr-9140f/databases/(default)/documents/SensorData/SensorData");

    clearDB(commandGet, commandDelete);
    // clearDB(sensorGet, sensorDelete);

    setupCurl(commandPost, "https://firestore.googleapis.com/v1/projects/ece445-early-response-dr-9140f/databases/(default)/documents/Commands");

}

/* -------------------------------------------  Boot Up Code  ------------------------------------------- */

void CommandControl::bootRWCommand() {
    pass("[Boot Command] ... Starting Boot");
    acceptorReadGUI.async_accept(
        ioc, 
        beast::bind_front_handler(
            &CommandControl::connectRWCommand,
            shared_from_this()
        )
    );
}

void CommandControl::connectRWCommand(beast::error_code ec, tcp::socket socket) {
    if (ec) {
        error("[Boot Command] ... TCP Connection Error");
        bootRWCommand();
    } else {
        pass("[Boot Command] ... TCP Connection Secured");
    }
    websocketReadGUI = make_shared<websocket::stream<tcp::socket>>(move(socket));
    websocketReadGUI->async_accept(
        beast::bind_front_handler(
            &CommandControl::acceptRWCommand,
            shared_from_this()
        )
    );
}

void CommandControl::acceptRWCommand(beast::error_code ec) {
    if (ec) {
        error("[Boot Command] ... Websocket Hanshake Failed");
    } else {
        pass("[Boot Command] ... Websocket Handshake Secured");
        doReadCommandValue();
    }
}

void CommandControl::bootRWSensor() {
    pass("[Boot Sensor] ... Starting Boot");
    acceptorWriteGUI.async_accept(
        ioc,
        beast::bind_front_handler(
            &CommandControl::connectRWSensor,
            shared_from_this()
        )
    );
}

void CommandControl::connectRWSensor(beast::error_code ec, tcp::socket socket) {
    if (ec) {
        error("[Boot Sensor] ... TCP Connection Error");
        bootRWCommand();
    } else {
        pass("[Boot Sensor] ... TCP Connection Secured");
    }
    websocketWriteGUI = make_shared<websocket::stream<tcp::socket>>(move(socket));
    websocketWriteGUI->async_accept(
        beast::bind_front_handler(
            &CommandControl::acceptRWSensor,
            shared_from_this()
        )
    );
}

void CommandControl::acceptRWSensor(beast::error_code ec) {
    if (ec) {
        error("[Boot Sensor] ... Websocket Hanshake Failed");
    } else {
        pass("[Boot Sensor] ... Websocket Handshake Secured");
        doReadSensorValue();
    }
}

/* -------------------------------------------  Data Communication Code  ------------------------------------------- */

void CommandControl::doReadCommandValue() {
    websocketReadGUI->async_read(
        bufferReadCommand,
        beast::bind_front_handler(
            &CommandControl::onReadCommandValue,
            shared_from_this()
        )
    );
}

void CommandControl::onReadCommandValue(beast::error_code ec, size_t bytes_transferred) {
    cout << to_string(bytes_transferred) << endl;
    if (ec) {
        error("[Read Command] ... Read Command Error");
    } else if (bytes_transferred == 0) {
        warning("[Read Command] ... Zero Bytes Read");
        doReadCommandValue();
    } else {
        pass("[Read Command] ... " + to_string(bytes_transferred) + " Bytes Read");
        {
            lock_guard<mutex> lock(mutexCommand);
            queueCommand.push(bufferReadCommand);
        }
        bufferReadCommand.clear();

        net::dispatch(ioc, [self = shared_from_this()] {
            self->doWriteCommandValue();
        });

        doReadCommandValue();
    }
}

void CommandControl::doWriteCommandValue() {

    {
        lock_guard<mutex> lock(mutexCommand);

        if (!queueCommand.empty()) {
            auto data = queueCommand.front().data();
            queueCommand.pop();
            string commandValue(net::buffer_cast<const char*>(data), net::buffer_size(data));

            cout << commandValue << endl;

            int servo_cmd = 0;
            int motor_speed = 0;

            std::stringstream ss(commandValue);
            std::string temp;

            std::getline(ss, temp, ':');
            ss >> servo_cmd;
            std::getline(ss, temp, ':');
            ss >> motor_speed;

            commandPost->params = R"({
                "fields": {
                    "servo_cmd": {
                        "stringValue": ")" + to_string(servo_cmd) + R"("
                    }, 
                    "motor_speed": {
                        "stringValue": ")" + to_string(motor_speed) + R"("
                    }
                }
            })";
        }
    }

    string commandUrl = commandPost->baseUrl + "?documentId=command" + to_string(commandPost->commandCount);
    curl_easy_setopt(commandPost->commandCurl, CURLOPT_POST, 1L);
    curl_easy_setopt(commandPost->commandCurl, CURLOPT_URL, commandUrl.data());
    curl_easy_setopt(commandPost->commandCurl, CURLOPT_POSTFIELDS, commandPost->params.data());
    commandPost->commandCount++;

    CURLcode res = curl_easy_perform(commandPost->commandCurl);
    if (res != CURLE_OK) {
        error("[Write Command] ... Post Request Failed: ");
        cerr << curl_easy_strerror(res) << endl;
    } else {
        pass("[Write Command] ... Post Request Succeeded");
    }

}

void CommandControl::doReadSensorValue() {
    string storage;
    {
        lock_guard<mutex> lock(mutexDataPacket);
        beast::flat_buffer buffer;

        curl_easy_setopt(sensorGet->commandCurl, CURLOPT_URL, sensorGet->baseUrl.data());
        curl_easy_setopt(sensorGet->commandCurl, CURLOPT_WRITEFUNCTION, clearDBCallback);
        curl_easy_setopt(sensorGet->commandCurl, CURLOPT_WRITEDATA, &storage);
        CURLcode res = curl_easy_perform(sensorGet->commandCurl);
        if (res != CURLE_OK) {
            error("[Sensor Data] ... GET Request Failed: ");
            cerr << curl_easy_strerror(res) << endl;
        } else {
            if (storage.size() > 3) 
                pass("[Sensor Data] ... GET Request Succeeded");
        }

        // Comment this Line for Production use
        this_thread::sleep_for(chrono::milliseconds(250));

        if (storage.size() > 3) {
            cout << storage << endl;
            buffer.commit(net::buffer_copy(buffer.prepare(storage.size()), net::buffer(storage)));
            queueDataPacket.push(std::move(buffer));
            curl_easy_setopt(sensorDelete->commandCurl, CURLOPT_URL, sensorDelete->baseUrl.data());
            curl_easy_setopt(sensorDelete->commandCurl, CURLOPT_CUSTOMREQUEST, "DELETE");
            curl_easy_perform(sensorDelete->commandCurl);
        }
    }

    if (storage.size() > 3) {
        doWriteSensorValue();
    } else {
        doReadSensorValue();
    }
}

void CommandControl::doWriteSensorValue() {
    websocketWriteGUI->async_write(
        queueDataPacket.front().data(),
        beast::bind_front_handler(
            &CommandControl::onWriteSensorValue,
            shared_from_this()
        )
    );
}

void CommandControl::onWriteSensorValue(beast::error_code ec, size_t bytes_transferred) {
    if (ec) {
        error("[Write Sensor] ... Write Sensor Error");
    } else if (bytes_transferred == 0) {
        warning("[Write Sensor] ... Zero Bytes Written");
        doWriteSensorValue();
    } else {
        pass("[Write Command] ... " + to_string(bytes_transferred) + " Bytes Written");
        {
            lock_guard<mutex> lock(mutexDataPacket);
            if (!queueDataPacket.empty()) {
                queueDataPacket.pop();
            }
        }
        doReadSensorValue();
    }
}

/* -------------------------------------------  Command Control Deconstructor Code  ------------------------------------------- */

CommandControl::~CommandControl() {
    curl_easy_cleanup(commandPost->commandCurl);
    curl_slist_free_all(commandPost->commandHeaders);

    curl_easy_cleanup(commandGet->commandCurl);
    curl_slist_free_all(commandGet->commandHeaders);

    curl_easy_cleanup(commandDelete->commandCurl);
    curl_slist_free_all(commandDelete->commandHeaders);

    curl_easy_cleanup(sensorGet->commandCurl);
    curl_slist_free_all(sensorGet->commandHeaders);

    curl_easy_cleanup(sensorDelete->commandCurl);
    curl_slist_free_all(sensorDelete->commandHeaders);
}