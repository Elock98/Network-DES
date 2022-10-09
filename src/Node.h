#ifndef _NODE_H_
#define _NODE_H_
#include "EventQueue.h"
#include "Link.h"
#include <string>
#include <iostream>

class Link;

class Node{
    private:
        int ip_addr;
        EventQueue* q;
        Link* conn;

    public:
        Node(int ip, EventQueue* queue);
        void set_link(Link* l);
        int get_addr();
        void send(std::string msg, double time); //Should take dest ip and message
        void recv(std::string msg); //Should take pointer to packet
};
#endif