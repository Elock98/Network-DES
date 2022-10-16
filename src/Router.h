#ifndef _ROUTER_H_
#define _ROUTER_H_

#include "EventQueue.h"
#include "Link.h"
#include "NetworkInterface.h"
#include "InterfaceLinkEntry.h"
#include "ConnectionInterface.h"

#include <string>
#include <iostream>
#include <vector>

class Link;
class NetInterface;

class Router: public Connection{
    private:
        std::vector<NetLinkPair*> _interfaces;
        EventQueue* _q;

        int _num_of_interfaces;

    public:
        Router(EventQueue* queue, std::vector<NetInterface*> interfaces);

        int connect_to_interface(Link* link, NetInterface* interface);
        int disconnect_from_interface(NetInterface* interface);

        void recv(std::string msg);

        void send(std::string msg, double time);
};

#endif
