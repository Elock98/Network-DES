#include "InterfaceLinkEntry.h"

using namespace std;


NetLinkPair::NetLinkPair(NetInterface* interface, Link* link){
    _interface = interface;
    _link = link;
}

void NetLinkPair::disconnect_link(){
    _link = NULL;
}

int NetLinkPair::connect_link(Link* link){
    if(_link == NULL){
        _link = link;
        cout << "New link connected to interface: " << _interface->get_ip_addr() << endl;
        return 0;
    }else{
        cout << "Link cannot be connected to interface: " << _interface->get_ip_addr() << " . Another link is already connected!" << endl;
        return -1;
    }
}

Link* NetLinkPair::get_link(){
    return _link;
}

NetInterface* NetLinkPair::get_netInterface(){
    return _interface;
}