#ifndef _NODE_H_
#define _NODE_H_
#include "EventQueue.h"
#include "Link.h"
#include "NetworkInterface.h"
#include "ConnectionInterface.h"
#include "Message.h"

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
        NetInterface* get_interface();
        void send(Message* msg, double time);
        void recv(Message* msg);
};
#endif
