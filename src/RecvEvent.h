#ifndef _RECV_EVENT_H_
#define _RECV_EVENT_H_
#include "EventQueue.h"
#include "ConnectionInterface.h"
#include "Message.h"

#include <string>

class RecvEvent: public Event{
    private:
        Connection* _self;
        Message* _msg;

    public:
        RecvEvent(Connection* self, double time, Message* message);
        void execute();
        double get_time();
};
#endif
