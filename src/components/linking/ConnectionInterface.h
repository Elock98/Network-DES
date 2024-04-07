#ifndef _CONNECTION_INTERFACE_H_
#define _CONNECTION_INTERFACE_H_

#include "../message/Message.h"

#include <string>

class Connection{
    public:
        virtual void send(Message* msg, double time) = 0;
        virtual void recv(Message* msg, double recv_time) = 0;
};

#endif
