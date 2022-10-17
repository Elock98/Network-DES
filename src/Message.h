#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "NetworkInterface.h"

#include <string>

class NetInterface;

class Message{
    private:
        std::string _data;
        NetInterface* _src;
        NetInterface* _dst;

    public:
        Message(NetInterface* from, NetInterface* to, std::string message);

        NetInterface* get_src();
        NetInterface* get_dst();
        std::string get_message();
};
#endif
