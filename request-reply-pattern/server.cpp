/* 
 * ZeroMQ - Request/Reply Pattern - Server Example
 * ------------------------------------------------
 * @author: Hakan Kaya
 * @description:
 *
 */

#include <iostream>
#include <zmq.hpp>
#include <string>

std::string helloMsg = "Hello from server!";

int main(){

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);

    socket.bind("tcp://*:5555");
    std::cout << "[+] Server is running... tcp://*:5555" << std::endl;

    while(true){
        zmq::message_t message;
        socket.recv(&message);
        std::cout << "   Received message: " << message << std::endl;
        
        zmq::message_t reply(helloMsg.size());
        memcpy(reply.data(), helloMsg.c_str(), helloMsg.size());
        socket.send(reply);
        std::cout << "   Sending reply: " << helloMsg << std::endl;
    }
}