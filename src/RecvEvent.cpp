#include "RecvEvent.h"

RecvEvent::RecvEvent(Connection* self, double time, std::string message){
    _self = self;
    exec_time = time;
    msg = message;
}

void RecvEvent::execute(){
    _self->recv(msg);
}

double RecvEvent::get_time(){
    return exec_time;
}
