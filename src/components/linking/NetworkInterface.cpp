#include "NetworkInterface.h"

using namespace std;

NetInterface::NetInterface(std::string ip, std::string subnet_mask){
    if(ip_check(ip) < 0 || subnet_check(subnet_mask) < 0){
        cout << "Network interface could not be created!" << endl;
        return;
    }
    ip_str = ip;
    net_str = subnet_mask;
}

int NetInterface::ip_check(std::string ip){
    stringstream ip_stream(ip);

    string segment;

    vector<string> ip_seg;

    // segment ip
    while(std::getline(ip_stream, segment, '.')){
       ip_seg.push_back(segment);
    }

    if(ip_seg.size() != 4){
        perror("Invalid number of segments for ip!");
        return -1;
    }

    for(int i = 0; i < ip_seg.size(); i++){
        if(stoi(ip_seg[i]) < 0 || stoi(ip_seg[i]) > 255){
            perror("Value of ip segment out of possible range!");
            return -1;
        }
    }

    int separation_counter = 0;
    for(int i = 0; i < ip.length(); i++){
        if(ip[i] == '.') separation_counter++;
    }

    if(separation_counter > 3){
        perror("Invalid number of segments for ip!");
        return -1;
    }

    return 0;
}

int NetInterface::subnet_check(std::string mask){
    stringstream mask_stream(mask);

    string segment;

    vector<string> mask_seg;

    // segment net_mask
    while(std::getline(mask_stream, segment, '.')){
       mask_seg.push_back(segment);
    }

    if(mask_seg.size() != 4){
        perror("Invalid number of segments for subnet mask!");
        return -1;
    }

    for(int i = 0; i < mask_seg.size(); i++){
        if(stoi(mask_seg[i]) < 0 || stoi(mask_seg[i]) > 255){
            perror("Value of netmask segment out of possible range!");
            return -1;
        }
        if(i > 0 && stoi(mask_seg[i]) > stoi(mask_seg[i-1])){
            perror("Invalid order of subnet mask segments!");
            return -1;
        }
    }

    int separation_counter = 0;
    for(int i = 0; i < mask.length(); i++){
        if(mask[i] == '.') separation_counter++;
    }

    if(separation_counter > 3){
        perror("Invalid number of segments for ip!");
        return -1;
    }
    return 0;
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
