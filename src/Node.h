#ifndef _NODE_H_
#define _NODE_H_
#include "EventQueue.h"
#include <string>
#include <iostream>

class Node{
    private:
        int ip_addr;
        EventQueue* q;

    public:
        Node(int ip, EventQueue* queue);
        int get_addr();
        void send(std::string msg, double time); //Should take dest ip and message
        void recv(std::string msg); //Should take pointer to packet
};
#endif