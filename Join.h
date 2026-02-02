#ifndef Join_h
#define Join_h

#include <ESP32Servo.h>

class Join {

private:
  Servo servo;
  unsigned char Deg;
  String Name;

public:
  Join(int SP, unsigned char StartDeg, String name);
  unsigned char get_Degree();
  void move(int deg);
  void update(int deg);
  String get_name();
};


#endif