#ifndef _CONNECTION_INTERFACE_H_
#define _CONNECTION_INTERFACE_H_

#include <string>

class Connection{
    public:
        virtual void send(std::string msg, double time) = 0;
        virtual void recv(std::string msg) = 0;
        virtual std::string get_addr() = 0; // Might want to change this later (switches should not have ip?)
};

#endif
