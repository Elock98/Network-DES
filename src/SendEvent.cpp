#include "SendEvent.h"

SendEvent::SendEvent(Node* self, double time, std::string message){
    _self = self;
    exec_time = time;
    msg = message;
}

void SendEvent::execute(){
    _self->send(msg, exec_time);
}

double SendEvent::get_time(){
    return exec_time;
}