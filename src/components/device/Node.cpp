#include "Node.h"

Node::Node(NetInterface* interface, EventQueue* queue){
    _interface = interface;
    q = queue;
}

void Node::send(Message* msg, double time){
    std::cout << "Sending message from ip: " << _interface->get_ip_addr() << std::endl;
    conn->transmit(msg, this, time);
}

void Node::recv(Message* msg, double recv_time){
    std::cout << "Node: " << _interface->get_ip_addr() <<
                 "\nReceived message: " << msg->get_message() <<
                 "\nFrom: " << msg->get_src()->get_ip_addr() << std::endl;
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

NetInterface* Node::get_interface(){
    return _interface;
}
