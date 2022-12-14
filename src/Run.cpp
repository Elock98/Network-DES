#include "EventQueue.h"
#include "sim_engine.h"
#include "Node.h"
#include "Link.h"
#include "SendEvent.h"
#include "NetworkInterface.h"
//#include "ConstantBitRateGenerator.h"
#include "Message.h"
#include "Router.h"


#include <iostream>
#include <vector>

int main(){
    EventQueue q;

    Node node1(new NetInterface("192.168.0.2", "255.255.255.0"), &q);
    Node node2(new NetInterface("192.168.1.2", "255.255.255.0"), &q);

    Link link1(0.4, &q);
    Link link2(0.4, &q);

    node1.connect_link(&link1);
    node2.connect_link(&link2);

    std::vector<NetInterface*> r1_int = {new NetInterface("192.168.0.1", "255.255.255.0"),
                                         new NetInterface("192.168.1.1", "255.255.255.0")};

    Router r1(&q, r1_int);

    r1.connect_to_interface(&link1, "192.168.0.1");

    r1.connect_to_interface(&link2, "192.168.1.1");

    q.add_event(new SendEvent(&node1, 0.0, new Message(node1.get_interface(), node2.get_interface(), "Test message 1")));

    SimEngine eng(&q);
    eng.run();

    return 0;
}
