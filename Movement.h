#ifndef Movement_h
#define Movement_h

#include "Move.h"

class Movement {
private:
  Move* moves;
  int size;
public:
  Movement(Move* arr, int Size);
  void execute();  //speed von 0 bis 100 ( 100 == max speed move 0 == 1)
  Move get_Move(int index);
  boolean check_Movement();
  void print();
};


#endif