#include "Movement.h"




Movement ::Movement(Move* arr, int Size) {
  moves = new Move[Size];  // Dynamisch ein Array erstellen
  size = Size;
  for (int i = 0; i < size; ++i) {
    moves[i] = Move(arr[i].get_Join(), arr[i].get_deg(), arr[i].get_speed(), arr[i].get_delayStart());
  }
}



void Movement::execute() {

  unsigned long totalTime = moves[0].get_total_Time();  //fehlt über alle
  for (int i = 0; i < size; ++i) {
    if (moves[i].get_total_Time() > totalTime) {
      totalTime = moves[i].get_total_Time();
      
    }
  }

  Serial.println(totalTime);
  unsigned long startTime = millis();
  while (millis() <= startTime + totalTime) {

    for (int i = 0; i < size; ++i) {
      moves[i].get_Join()->move(moves[i].get_funktion_Deg(startTime));
      
    }
  }
  for (int i = 0; i < size; ++i) {
    int deg = moves[i].get_deg();
    moves[i].get_Join()->move(deg);
    moves[i].get_Join()->update(deg);
  }
}


Move Movement::get_Move(int index) {
  return moves[index];
}

boolean Movement::check_Movement() {
  for (int i = 0; i < size; i++) {
    if (moves[i].get_Join()->get_Degree() != moves[i].get_deg()) {
    Serial.print(moves[i].get_Join()->get_name() );
    Serial.print("  join: ");
    Serial.print(moves[i].get_Join()->get_Degree());
    Serial.println(moves[i].get_deg());
    }
  }
  return true;
}

void Movement :: print(){
  for (int i = 0; i < size; i++) {
   
    Serial.print(moves[i].get_Join()->get_name() );
    Serial.print(" :   ");
    Serial.println(moves[i].get_deg());
    
  }
}
