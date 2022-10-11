#ifndef _NODE_H_
#define _NODE_H_
#include "EventQueue.h"
#include "Link.h"
#include "NetworkInterface.h"
#include <string>
#include <iostream>

class Link;
class NetInterface;

class Node{
    private:
        NetInterface* _interface;
        EventQueue* q;
        Link* conn;

    public:
        Node(NetInterface* interface, EventQueue* queue);
        void set_link(Link* l);
        std::string get_addr();
        void send(std::string msg, double time); //Should take dest ip and message
        void recv(std::string msg); //Should take pointer to packet
};
#endif