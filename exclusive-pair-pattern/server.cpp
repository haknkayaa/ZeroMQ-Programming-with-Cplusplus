/* 
 * ZeroMQ - Exclusive Pair Pattern - Server Example
 * ------------------------------------------------
 * @author: Hakan Kaya
 * @description:
 *
 */

#include <iostream>
#include <unistd.h>
#include <zmq.hpp>
#include <string>

std::string helloMsg = "Hello from server!";

int main(){

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PAIR);

    socket.bind("tcp://*:5555");
    std::cout << "[+] Server is running... tcp://*:5555" << std::endl;

    auto id = 0;
    auto time = std::time(nullptr);

    while(true){
        sleep(1);
        id = id + 1;
        time = std::time(nullptr);

        // message format: <id> <time> <message>
        std::string message = std::to_string(id) + " " + std::to_string(time) + " " + helloMsg;
        zmq::message_t msg(message.size());
        memcpy(msg.data(), message.c_str(), message.size());
        socket.send(msg);

        std::cout << "   Sending message: " << message << std::endl;
    }
}