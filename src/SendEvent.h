#ifndef _SEND_EVENT_H_
#define _SEND_EVENT_H_
#include "EventQueue.h"
#include "Node.h"
#include <string>
#include <iostream>

class SendEvent: public Event{
    private:
        Node* _self;
        std::string msg;

    public:
        SendEvent(Node* self, double time, std::string message);
        void execute();
        double get_time();
};
#endif