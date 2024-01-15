/*
 * ZeroMQ - Request/Reply Pattern - Client Example
 * ------------------------------------------------
 * @author: Hakan Kaya
 * @description:
 *
 */

#include <iostream>
#include <string>
#include <unistd.h>
#include <zmq.hpp>


std::string helloMsg = "Hello from client!";

int main() {

  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REQ);

  socket.connect("tcp://localhost:5555");
  std::cout << "[+] Connecting to server... tcp://localhost:5555" << std::endl;

  while (true) {
    zmq::message_t request(helloMsg.size());
    memcpy(request.data(), helloMsg.c_str(), helloMsg.size());
    socket.send(request);
    std::cout << "    Sending message: " << helloMsg << std::endl;

    zmq::message_t reply;
    socket.recv(&reply); // Add this line
    std::cout << "    Received reply: " << std::string(static_cast<char*>(reply.data()), reply.size()) << std::endl;

    sleep(1);
  }
}