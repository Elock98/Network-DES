#include "Router.h"

using namespace std;

Router::Router(EventQueue* queue, std::vector<NetInterface*> interfaces, double routing_delay){
    _q = queue;
    _num_of_interfaces = interfaces.size();
    _routing_delay = routing_delay;

    /*
        Check that multiple interfaces don't belong
        to the same network. If the check passes the
        interface can be added.
    */
    vector<string> network_addresses;
    for(int i = 0; i < _num_of_interfaces; i++){
        string addr = interfaces[i]->get_network_addr();
        for(int i = 0; i < network_addresses.size(); i++){
            if(addr == network_addresses[i]){
                cout << "Two router interfaces can't belong to the same network!" << endl;
                return;
            }
        }
        network_addresses.push_back(addr);

        // Add interface to router
        _interfaces.push_back(new NetLinkPair(interfaces[i]));
    }
}

int Router::connect_to_interface(Link* link, string interface_ip){
    for(int i = 0; i < _interfaces.size(); i++){
        if(_interfaces[i]->get_netInterface()->get_ip_addr() == interface_ip){
            if(_interfaces[i]->connect_link(link) < 0){
                cout << "Could not connect..." << endl;
                return -1;
            }else{
                link->connect_link(this);
                return 0;
            }
        }
    }
    cout << "Router does not have an interface with IP: " << interface_ip << endl;
    return -1;
}

int Router::disconnect_from_interface(string interface_ip){
    for(int i = 0; i < _interfaces.size(); i++){
        if(_interfaces[i]->get_netInterface()->get_ip_addr() == interface_ip){
            _interfaces[i]->disconnect_link();
            return 0;
        }
    }
    cout << "Router does not have an interface with IP: " << interface_ip << endl;
    return -1;
}

void Router::recv(Message* msg, double recv_time){
    cout << "Router received a message\n" <<
            "From: " << msg->get_src()->get_ip_addr() <<
            "\nTo: " << msg->get_dst()->get_ip_addr() << endl;
    _q->add_event(new SendEvent(this, recv_time + this->_routing_delay, msg));
}

void Router::send(Message* msg, double time){
    /*
        The router needs to grab dest ip from the message
        in order to find what link to transmit the msg
        over.
    */
    std::string dst = msg->get_dst()->get_network_addr();
    for(int i = 0; i < _interfaces.size(); i++){
        if(_interfaces[i]->get_netInterface()->get_network_addr() == dst){
            _interfaces[i]->get_link()->transmit(msg, this, time);
            return;
        }
    }
}
