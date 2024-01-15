/* 
 * ZeroMQ - Exclusive Pair Pattern - Client Example
 * ------------------------------------------------
 * @author: Hakan Kaya
 * @description:
 *
 */

#include <iostream>
#include <unistd.h>
#include <zmq.hpp>
#include <string>

std::string helloMsg = "Hello from client!";

int main(){

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PAIR);

    socket.connect("tcp://localhost:5555");
    std::cout << "[+] Client is running... tcp://localhost:5555" << std::endl;

    while(true){
        zmq::message_t request;
        socket.recv(&request);
        std::string message = std::string(static_cast<char*>(request.data()), request.size());
        std::cout << "   Received message: " << message << std::endl;
    }
}