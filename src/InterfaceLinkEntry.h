#ifndef _INTERFACE_LINK_ENTRY_H_
#define _INTERFACE_LINK_ENTRY_H_

#include "Link.h"
#include "NetworkInterface.h"

#include <iostream>

class Link;
class NetInterface;

class NetLinkPair{
    private:
        Link* _link;
        NetInterface* _interface;

    public:
        NetLinkPair(NetInterface* interface, Link* link=NULL);

        void disconnect_link();
        int connect_link(Link* link);

        Link* get_link();
        NetInterface* get_netInterface();

};
#endif