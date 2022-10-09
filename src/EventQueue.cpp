#include "EventQueue.h"

void EventQueue::sort_queue(){
    std::sort(queue.begin(), queue.end());
}

// Removes the next event from the queue and returns it.
Event* EventQueue::get_event(){
    Event* ev = queue.back();
    queue.pop_back();
    return ev;
}

void EventQueue::add_event(Event* ev){
    queue.push_back(ev);
    sort_queue();
}

void EventQueue::print(){
    for(Event* ev: queue){
        std::cout << "Time: " << ev->get_time() << std::endl;
    }
}

bool EventQueue::is_empty(){
    return (queue.size() == 0);
}