#include "Link.h"

using namespace std;

Link::Link(double propagation_delay, EventQueue* queue){
    _conn1 = NULL;
    _conn2 = NULL;

    delay = propagation_delay;
    q = queue;
}

void Link::connect_link(Connection* new_conn){
    /*
        If conn1 is free set conn1 = new_conn
        else if conn2 is free set conn2 = new_conn
        else message error "Link cannot connect to more than 2 devices!"
    */
    if(_conn1 == NULL){
        _conn1 = new_conn;
    }else if(_conn2 == NULL){
        _conn2 = new_conn;
    }else{
        cout << "Link cannot connect to more than 2 devices!" << endl;
    }
}

void Link::disconnect_link(Connection* rm_conn){
    /*
        If rm_conn == conn1, set conn1 to NULL
        else if rm_conn == conn2, set conn2 to NULL
        else message error "Link is not connected to the device!"
    */
    if(rm_conn == _conn1){
        _conn1 = NULL;
    }else if(rm_conn == _conn2){
        _conn2 = NULL;
    }else{
        cout << "Link cannot disconnect from unconnected device" << endl;
    }
}

void Link::transmit(Message* msg, Connection* self, double current_time){
    if(_conn1 == NULL || _conn2 == NULL){
        cout << "Message cannot be sent over link, there needs to be two devices connected!" << endl;
        return;
    }

    if(self == _conn1){
        //Create recv event for node2
        cout << "Sending '" << msg->get_message() << "' over link" << endl;
        q->add_event(new RecvEvent(_conn2, current_time + delay, msg));
    }else if(self == _conn2){
        //Create recv event for node1
        cout << "Sending '" << msg->get_message() << "' over link" << endl;
        q->add_event(new RecvEvent(_conn1, current_time + delay, msg));
    }else{
        cout << "Error occured on link." << endl;
    }
}
