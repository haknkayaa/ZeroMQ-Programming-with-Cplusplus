/* 
 * ZeroMQ - Usage Proxy Example - Producer
 * ------------------------------------------------
 * @author: Hakan Kaya
 * @description:
 *
 */

#include <iostream>
#include <unistd.h>
#include <zmq.hpp>
#include <string>

std::string helloMsg = "Hello from producer!";

// #define XPUB_ENDPOINT "tcp://localhost:9200"
#define XSUB_ENDPOINT "tcp://localhost:9210"


int main(){

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PUB);

    socket.connect(XSUB_ENDPOINT);
    std::cout << "[+] Producer is running... " << XSUB_ENDPOINT << std::endl;

    while(true){
        zmq::message_t message(helloMsg.size());
        memcpy(message.data(), helloMsg.c_str(), helloMsg.size());
        socket.send(message);
        std::cout << "   Sending message: " << helloMsg << std::endl;
        sleep(1);
    }

}