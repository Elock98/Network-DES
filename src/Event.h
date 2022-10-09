#ifndef _EVENT_H_
#define _EVENT_H_

// Interface for events.
class Event{
    protected:
        double exec_time;

    public:
        virtual double get_time() = 0;
        virtual void execute() = 0;

        // Used to sort Events by time.
        bool operator< (const Event &other) const {
            return exec_time > other.exec_time;
        }
};
#endif