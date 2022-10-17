#ifndef _CONNECTION_INTERFACE_H_
#define _CONNECTION_INTERFACE_H_

#include "Message.h"

#include <string>

class Connection{
    public:
        virtual void send(Message* msg, double time) = 0;
        virtual void recv(Message* msg) = 0;
};

#endif
