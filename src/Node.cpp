#include "Node.h"

Node::Node(int ip, EventQueue* queue){
    ip_addr = ip;
    q = queue;
}

void Node::send(std::string msg, double time){
    std::cout << "Sending message from ip: " << ip_addr << std::endl;
}

void Node::recv(std::string msg){
    std::cout << "Recv: " << msg << std::endl;
}

int Node::get_addr(){
    return ip_addr;
}