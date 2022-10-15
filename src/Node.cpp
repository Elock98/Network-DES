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

void Node::connect_link(Link* l){
    conn = l;
    conn->connect_link(this);
}

void Node::disconnect_link(){
    if(conn == NULL){
        std::cout << "No link to disconnect!" << std::endl;
        return;
    }
    conn->disconnect_link(this);
    conn = NULL;
}

std::string Node::get_addr(){
    return _interface->get_ip_addr();
}
