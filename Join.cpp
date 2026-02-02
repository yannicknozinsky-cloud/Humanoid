#include "Join.h"
#include <ESP32Servo.h>

#define MaxTimePerDegree 350
#define MinTimePerDegree 2

Join::Join(int ServoPin, unsigned char StartDeg, String name) {
  Name = name;
  servo.attach(ServoPin);
 if(StartDeg < 0){
    Deg = 0;
    Serial.println("Join Degree to small ");
  }else if(StartDeg > 180){
    Serial.println("Join Degree to big ");
    Deg = 180;
  }else{
    Deg = StartDeg;  
  }
  servo.write(Deg);
}

void Join ::move(int deg) {
  servo.write(deg);
}

void Join::update(int deg) {
  Deg = deg;
}

unsigned char Join::get_Degree() {
  return Deg;
}

String Join :: get_name(){
  return Name;
}
