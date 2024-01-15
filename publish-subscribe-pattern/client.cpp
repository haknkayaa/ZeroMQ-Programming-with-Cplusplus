/* 
 * ZeroMQ - Publish/Subscribe Pattern - Client Example
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
    zmq::socket_t socket(context, ZMQ_SUB);

    
    socket.connect("tcp://localhost:5555"); 
    std::cout << "[+] Client is running... tcp://localhost:5555" << std::endl;

    const char *filter = "";
    socket.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

    while(true){
        zmq::message_t msg;
        socket.recv(&msg);

        std::string message = std::string(static_cast<char*>(msg.data()), msg.size());
        std::cout << "Received message: " << message << std::endl;
    }
}