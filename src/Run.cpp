#include "EventQueue.h"
#include "sim_engine.h"
#include "Node.h"
#include "Link.h"
#include "SendEvent.h"
#include "NetworkInterface.h"

int main(){
    EventQueue q;
    Node node1(new NetInterface("192.168.0.2", "255.255.255.0"), &q);
    Node node2(new NetInterface("192.168.0.4", "255.255.255.0"), &q);
    Link link(&node1, &node2, 0.4, &q);

    q.add_event(new SendEvent(&node1, 0.0, "The first message sent!"));
    q.add_event(new SendEvent(&node2, 0.3, "The second message sent!"));
    q.add_event(new SendEvent(&node1, 1.3, "The third message sent!"));

    SimEngine eng(&q);
    eng.run();

    return 0;
}