#include "Node.h"

Node::Node(int ip, EventQueue* queue){
    ip_addr = ip;
    q = queue;
}

void Node::send(std::string msg, double time){
    std::cout << "Sending message from ip: " << ip_addr << std::endl;
    conn->transmit(msg, ip_addr, time);
}

void Node::recv(std::string msg){
    std::cout << "Node with ip " << ip_addr << " received message: " << msg << std::endl;
}

void Node::set_link(Link* l){
    conn = l;
}

int Node::get_addr(){
    return ip_addr;
}