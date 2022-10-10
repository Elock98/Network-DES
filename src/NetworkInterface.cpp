#include "NetworkInterface.h"

using namespace std;

NetInterface::NetInterface(std::string ip, std::string subnet_mask){
    ip_str = ip;
    net_str = subnet_mask;
}

std::string NetInterface::get_network_addr(){
    stringstream temp_ip(ip_str);
    stringstream temp_net_mask(net_str);

    string segment;

    vector<string> ip_seg;
    vector<string> net_mask_seg;

    // segment ip
    while(std::getline(temp_ip, segment, '.')){
       ip_seg.push_back(segment);
    }

    // segment net_mask
    while(std::getline(temp_net_mask, segment, '.')){
       net_mask_seg.push_back(segment);
    }
    string net_addr;

    for(int i = 0; i < ip_seg.size(); i++){
        if(i < ip_seg.size() - 1){
            net_addr += to_string(stoi(ip_seg[i]) & stoi(net_mask_seg[i])) + ".";
        }else{
            net_addr += to_string(stoi(ip_seg[i]) & stoi(net_mask_seg[i]));
        }
    }

    return net_addr;
}

std::string NetInterface::get_host_addr(){
    stringstream temp_ip(ip_str);
    stringstream temp_net_mask(net_str);

    string segment;

    vector<string> ip_seg;
    vector<string> net_mask_seg;

    // segment ip
    while(std::getline(temp_ip, segment, '.')){
       ip_seg.push_back(segment);
    }

    // segment net_mask
    while(std::getline(temp_net_mask, segment, '.')){
       net_mask_seg.push_back(segment);
    }
    string host_addr;

    for(int i = 0; i < ip_seg.size(); i++){
        if(i < ip_seg.size() - 1){
            host_addr += to_string(stoi(ip_seg[i]) & ~stoi(net_mask_seg[i])) + ".";
        }else{
            host_addr += to_string(stoi(ip_seg[i]) & ~stoi(net_mask_seg[i]));
        }
    }

    return host_addr;
}

std::string NetInterface::get_broadcast_addr(){
    stringstream temp_ip(ip_str);
    stringstream temp_net_mask(net_str);

    string segment;

    vector<string> ip_seg;
    vector<string> net_mask_seg;

    // segment ip
    while(std::getline(temp_ip, segment, '.')){
       ip_seg.push_back(segment);
    }

    // segment net_mask
    while(std::getline(temp_net_mask, segment, '.')){
       net_mask_seg.push_back(segment);
    }
    string net_addr;

    for(int i = 0; i < ip_seg.size(); i++){
        if(i < ip_seg.size() - 1){
            bitset<8> ip_bits = stoi(ip_seg[i]);
            bitset<8> netmask_bits = ~stoi(net_mask_seg[i]);
            net_addr += to_string((ip_bits | netmask_bits).to_ulong()) + ".";
        }else{
            bitset<8> ip_bits = stoi(ip_seg[i]);
            bitset<8> netmask_bits = ~stoi(net_mask_seg[i]);
            net_addr += to_string((ip_bits | netmask_bits).to_ulong());
        }
    }

    return net_addr;
}

std::string NetInterface::get_ip_addr(){
    return ip_str;
}

std::string NetInterface::get_subnet_mask(){
    return net_str;
}