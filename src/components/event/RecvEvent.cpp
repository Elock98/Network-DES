#include "RecvEvent.h"

RecvEvent::RecvEvent(Connection* self, double time, Message* message){
    _self = self;
    exec_time = time;
    _msg = message;
}

void RecvEvent::execute(){
    _self->recv(_msg);
}

double RecvEvent::get_time(){
    return exec_time;
}
