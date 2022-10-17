#include "Message.h"

Message::Message(NetInterface* from, NetInterface* to, std::string message){
    _src = from;
    _dst = to;
    _data = message;
}

NetInterface* Message::get_src(){
    return _src;
}

NetInterface* Message::get_dst(){
    return _dst;
}

std::string Message::get_message(){
    return _data;
}
