#ifndef _RECV_EVENT_H_
#define _RECV_EVENT_H_
#include "EventQueue.h"
#include "ConnectionInterface.h"

#include <string>

class RecvEvent: public Event{
    private:
        Connection* _self;
        std::string msg;

    public:
        RecvEvent(Connection* self, double time, std::string message);
        void execute();
        double get_time();
};
#endif
