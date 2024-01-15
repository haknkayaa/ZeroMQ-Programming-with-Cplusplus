/* 
 * ZeroMQ - Usage Proxy Example - Proxy
 * ------------------------------------------------
 * @author: Hakan Kaya
 * @description:
 *
 */

#include <iostream>
#include <zmq.hpp>
#include <string>

std::string helloMsg = "Hello from proxy!";

int main(){

    zmq::context_t context(1);
    zmq::socket_t frontend(context, ZMQ_XPUB);  

    frontend.bind("tcp://*:9200");
    std::cout << "[+] Proxy is connection to producer... tcp://*:9200" << std::endl;

    zmq::socket_t backend(context, ZMQ_XSUB);
    backend.bind("tcp://*:9210");
    std::cout << "[+] Proxy is connection to subscriber... tcp://*:9210" << std::endl;

    zmq::proxy(frontend, backend, nullptr);

    return 0;
}