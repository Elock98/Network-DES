#ifndef _RECV_EVENT_H_
#define _RECV_EVENT_H_
#include "EventQueue.h"
#include "Node.h"
#include <string>

class Node;

class RecvEvent: public Event{
    private:
        Node* _self;
        std::string msg;

    public:
        RecvEvent(Node* self, double time, std::string message);
        void execute();
        double get_time();
};
#endif