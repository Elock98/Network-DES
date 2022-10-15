#include "Node.h"

Node::Node(NetInterface* interface, EventQueue* queue){
    _interface = interface;
    q = queue;
}

void Node::send(std::string msg, double time){
    std::cout << "Sending message from ip: " << _interface->get_ip_addr() << std::endl;
    conn->transmit(msg, this, time);
}

void Node::recv(std::string msg){
    std::cout << "Node with ip " << _interface->get_ip_addr() << " received message: " << msg << std::endl;
}

void Node::set_link(Link* l){
    conn = l;
}

std::string Node::get_addr(){
    return _interface->get_ip_addr();
}
