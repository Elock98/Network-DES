#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "EventQueue.h"
#include "Link.h"
#include "NetworkInterface.h"
#include "InterfaceLinkEntry.h"
#include "ConnectionInterface.h"
#include "Message.h"
#include "SendEvent.h"

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

    public:
        Router(EventQueue* queue, std::vector<NetInterface*> interfaces);

        int connect_to_interface(Link* link, std::string interface);
        int disconnect_from_interface(std::string interface);

        void recv(Message* msg);

        void send(Message* msg, double time);
};

#endif
