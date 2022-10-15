#ifndef _NODE_H_
#define _NODE_H_
#include "EventQueue.h"
#include "Link.h"
#include "NetworkInterface.h"
#include "ConnectionInterface.h"
#include <string>
#include <iostream>

class Link;
class NetInterface;

class Node: public Connection{
    private:
        NetInterface* _interface;
        EventQueue* q;
        Link* conn;

    public:
        Node(NetInterface* interface, EventQueue* queue);
        void connect_link(Link* l);
        void disconnect_link();
        std::string get_addr();
        void send(std::string msg, double time); //Should take dest ip and message
        void recv(std::string msg); //Should take pointer to packet
};
#endif
