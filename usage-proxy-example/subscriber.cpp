/* 
 * ZeroMQ - Usage Proxy Example - Subscriber
 * ------------------------------------------------
 * @author: Hakan Kaya
 * @description:
 *
 */

#include <iostream>
#include <zmq.hpp>
#include <string>

std::string helloMsg = "Hello from subscriber!";

int main(){

    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_SUB);

    socket.connect("tcp://localhost:9200");
    const char *filter = "";
    socket.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));
    std::cout << "[+] Subscriber is running... " << std::endl;

    while(true){
        zmq::message_t message;
        socket.recv(&message);
        std::string msg = std::string(static_cast<char*>(message.data()), message.size());
        std::cout << "   Received message: " << msg << std::endl;
    }
}