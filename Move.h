#ifndef Move_h
#define Move_h

#include"Join.h"

class Move
{

private:
     Join* join;
     int deg;
     int maxSpeed; //(interpret as delay)
     unsigned long delayStart;


public:
    Move() : join(nullptr), deg(0), maxSpeed(0), delayStart(0) {}
    Move(Join* j, int d, int s,  unsigned long dS); 
    int get_funktion_Deg(unsigned long startTime);
    unsigned long get_total_Time();
    int get_deg();
    int get_speed();
    unsigned long get_delayStart();
    Join* get_Join();
     void set_join(Join* j);
    void set_deg(int d);
    void set_speed(int s);
    void set_delayStart(int dS);
};


#endif