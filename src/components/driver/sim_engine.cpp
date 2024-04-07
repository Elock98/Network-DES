#include "sim_engine.h"

using namespace std;

SimEngine::SimEngine(EventQueue* queue){
    q = queue;
}

void SimEngine::run(){

    while(!q->is_empty()){
        cout << "-----------Event-----------" << endl;
        Event* e = q->get_event();
        cout << "Event time: " << e->get_time() << endl;
        this->sim_time = e->get_time();
        e->execute(this->get_time());
    }
}

double SimEngine::get_time(){
    return sim_time;
}
