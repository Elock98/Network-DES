#ifndef _LINK_H_
#define _LINK_H_
#include "EventQueue.h"
#include "Node.h"
#include "RecvEvent.h"
#include <string>
#include <iostream>

class Node;

class Link{
    private:
        Node* addr1;
        Node* addr2;

        double delay;

        EventQueue* q;

    public:
        Link(Node* node1, Node* node2, double propagation_delay, EventQueue* queue);
        void transmit(std::string msg, int self, double current_time); // int self is temp (will be taken from header later)
};
#endif