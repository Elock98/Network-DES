#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "../event/EventQueue.h"
#include "../linking/Link.h"
#include "../linking/NetworkInterface.h"
#include "../linking/InterfaceLinkEntry.h"
#include "../linking/ConnectionInterface.h"
#include "../message/Message.h"
#include "../event/SendEvent.h"

#include <string>
#include <iostream>
#include <vector>

class Link;
class NetInterface;
class NetLinkPair;

class Router: public Connection{
    private:
        std::vector<NetLinkPair*> _interfaces;
        EventQueue* _q;

        int _num_of_interfaces;
        double _routing_delay;

    public:
        Router(EventQueue* queue, std::vector<NetInterface*> interfaces, double routing_delay);

        int connect_to_interface(Link* link, std::string interface);
        int disconnect_from_interface(std::string interface);

        void recv(Message* msg, double recv_time);

        void send(Message* msg, double time);
};

#endif
