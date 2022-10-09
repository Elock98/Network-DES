#include "EventQueue.h"
#include "sim_engine.h"
#include "Node.h"
#include "Link.h"
#include "SendEvent.h"

int main(){
    EventQueue q;
    Node node1(1, &q);
    Node node2(2, &q);
    Link link(&node1, &node2, 0.4, &q);

    node1.set_link(&link);
    node2.set_link(&link);

    q.add_event(new SendEvent(&node1, 0.0, "The first message sent!"));
    SimEngine eng(&q);
    eng.run();

    return 0;
}