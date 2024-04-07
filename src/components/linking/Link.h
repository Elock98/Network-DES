#ifndef _LINK_H_
#define _LINK_H_
#include "../event/EventQueue.h"
#include "../event/RecvEvent.h"
#include "ConnectionInterface.h"
#include "../message/Message.h"

#include <string>
#include <iostream>


class Link{
    private:
        Connection* _conn1;
        Connection* _conn2;

        double delay;

        EventQueue* q;

    public:
        Link(double propagation_delay, EventQueue* queue);
        void connect_link(Connection* new_conn);
        void disconnect_link(Connection* rm_conn);
        void transmit(Message* msg, Connection* self, double current_time);
};
#endif
