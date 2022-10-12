#ifndef _NETWORK_INTERFACE_H_
#define _NETWORK_INTERFACE_H_

#include <string>
#include <vector>
#include <sstream>
#include <bitset>
#include <iostream>

class NetInterface{
    private:
        std::string ip_str;
        std::string net_str;

        int ip_check(std::string ip);
        int subnet_check(std::string mask);

    public:
        NetInterface(std::string ip, std::string subnet_mask);

        std::string get_network_addr();
        std::string get_host_addr();
        std::string get_ip_addr();
        std::string get_subnet_mask();
        std::string get_broadcast_addr();
};
#endif