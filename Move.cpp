#include "Move.h"
#define MaxTimePerDegree 350
#define MinTimePerDegree 2

Move::Move(Join* j, int d, int s, unsigned long dS) {
  
  join = j;
  if(d < 0){
    deg = 0;
    Serial.println("Move Degree to small ");
  }else if(d > 180){
    Serial.println("Move Degree to big ");
    deg = 180;
  }else{
    deg = d;  
  }
  if(s <= 0){
    maxSpeed = 1;
    Serial.println("Move speed to small ");
  }else if(s >= 100){
    Serial.println("Move speed to big ");
    maxSpeed = 100;
  }else{
    maxSpeed = s;  
  }
  delayStart = dS;
}



int Move::get_funktion_Deg(unsigned long startTime) {

  float DeltaDeg = deg - join->get_Degree();
  
  float DeltaTime = maxSpeed * abs(DeltaDeg);

  if (millis() <= startTime + delayStart) {
    return join->get_Degree();
  } else if (millis() <= startTime + delayStart + DeltaTime) {
    return ((DeltaDeg / DeltaTime) * (millis() - delayStart - startTime) + join->get_Degree());
  } else {
    return deg;
  }
}

unsigned long Move ::get_total_Time() {
  float DeltaDeg = deg - join->get_Degree();
  float DeltaTime = maxSpeed * abs(DeltaDeg);
  return DeltaTime + delayStart;
}

int Move ::get_deg() {
  return deg;
}
int Move ::get_speed() {
  return maxSpeed;
}
unsigned long Move ::get_delayStart() {
  return delayStart;
}

Join* Move::get_Join() {
  return join;
}

void Move ::set_join(Join* j) {
  join = j;
}
void Move ::set_deg(int d) {
  deg = d;
}
void Move ::set_speed(int s) {
  maxSpeed = s;
}
void Move ::set_delayStart(int dS) {
  delayStart = dS;
}
