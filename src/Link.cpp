#include "Link.h"

using namespace std;

Link::Link(Node* node1, Node* node2, double propagation_delay, EventQueue* queue){
    addr1 = node1;
    addr2 = node2;
    delay = propagation_delay;
    q = queue;
}

void Link::transmit(string msg, int self, double current_time){
    if(self == addr1->get_addr()){
        //Create recv event for node2
        cout << "Sending msg over link from node1 to node2..." << endl;
        q->add_event(new RecvEvent(addr2, current_time + delay, msg));
    }else if(self == addr2->get_addr()){
        //Create recv event for node1
        cout << "Sending msg over link from node2 to node1..." << endl;
        q->add_event(new RecvEvent(addr1, current_time + delay, msg));
    }else{
        cout << "Error occured on link." << endl;
    }
}