#include "sim_engine.h"

using namespace std;

SimEngine::SimEngine(EventQueue* queue){
    q = queue;
}

void SimEngine::run(){

    while(!q->is_empty()){
        Event* e = q->get_event();
        cout << "Event time: " << e->get_time() << endl;
        e->execute();
    }
}

double SimEngine::get_time(){
    return sim_time;
}