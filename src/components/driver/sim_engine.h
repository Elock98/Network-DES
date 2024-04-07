#ifndef _SIM_ENGINE_H_
#define _SIM_ENGINE_H_
#include "../event/EventQueue.h"
#include <iostream>

class SimEngine{
    private:
        double sim_time = 0.0;
        EventQueue *q;
    public:
        SimEngine(EventQueue* queue);
        void run();
        double get_time();

};
#endif
