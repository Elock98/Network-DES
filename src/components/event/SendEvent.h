#ifndef _SEND_EVENT_H_
#define _SEND_EVENT_H_

#include "EventQueue.h"
#include "../linking/ConnectionInterface.h"
#include "../message/Message.h"

#include <string>
#include <iostream>

class SendEvent: public Event{
    private:
        Connection* _self;
        Message* _msg;

    public:
        SendEvent(Connection* self, double time, Message* message);
        void execute(double current_time);
        double get_time();
};
#endif