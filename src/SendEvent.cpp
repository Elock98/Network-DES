#include "SendEvent.h"

SendEvent::SendEvent(Connection* self, double time, Message* message){
    _self = self;
    exec_time = time;
    _msg = message;
}

void SendEvent::execute(){
    _self->send(_msg, exec_time);
}

double SendEvent::get_time(){
    return exec_time;
}
