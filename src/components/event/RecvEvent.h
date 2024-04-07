#ifndef _RECV_EVENT_H_
#define _RECV_EVENT_H_
#include "EventQueue.h"
#include "../linking/ConnectionInterface.h"
#include "../message/Message.h"

#include <string>

class RecvEvent: public Event{
    private:
        Connection* _self;
        Message* _msg;

    public:
        RecvEvent(Connection* self, double time, Message* message);
        void execute(double current_time);
        double get_time();
};
#endif
