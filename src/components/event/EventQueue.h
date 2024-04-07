#ifndef _EVENT_QUEUE_H_
#define _EVENT_QUEUE_H_

#include "Event.h"
#include <vector>
#include <bits/stdc++.h>

class EventQueue{
    private:
        std::vector<Event*>queue;

        void sort_queue(); // sorts the queue by time in ascending order.

    public:
        Event* get_event(); // pops event from the event queue.

        void add_event(Event* ev); // adds event to the queue.

        void print();

        bool is_empty();

};
#endif