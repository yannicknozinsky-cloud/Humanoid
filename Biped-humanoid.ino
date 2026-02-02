#include <ESP32Servo.h>
#include "Join.h"
#include "Movement.h"
#include "Move.h"


Join R_Upper_Knee(27, 80, "R Upper Knee");
Join R_Hip(12, 90, "R Hip");
Join L_Hip(0, 100, "L Hip");
Join R_Under_Knee(14, 80, "R Under Knee");
Join L_Foot_Front(32, 90, "L Foot Front");
Join L_Foot_Back(35, 90, "L Foot Back");
Join R_Foot_Front(33, 85, "R Foot Front");
Join R_Foot_Back(26, 92, "R Foot Back");
Join L_Upper_Knee(2, 90, "L Upper Knee");
Join L_Under_Knee(23, 80, "L Under Knee");
Join Core(4, 90, "Core");
Join R_Shoulder_Rotate(16, 90, "R Shoulder Rotate");
Join L_Soulder_Rotate(5, 90, "L Shoulder Rotate");
Join R_Shoulder_Lift(18, 90, "R Shoulder Lift");
Join L_Shoulder_Lift(19, 90, "L Shoulder Lift");
Join R_Ellbow(21, 90, "R Ellbow");
Join L_Ellbow(22, 90, "L Ellbow");


Move Stand_R_Hip(&R_Hip, 90, 50, 1);
Move Stand_L_Hip(&L_Hip, 88, 50, 1);
Move Stand_R_Upper_Knee(&R_Upper_Knee, 80, 50, 1);
Move Stand_L_Upper_Knee(&L_Upper_Knee, 90, 50, 1);
Move Stand_R_Under_Knee(&R_Under_Knee, 80, 50, 1);
Move Stand_L_Under_Knee(&L_Under_Knee, 80, 50, 1);
Move Stand_R_Foot_Front(&R_Foot_Front, 91, 50, 1);
Move Stand_L_Foot_Front(&L_Foot_Front, 92, 50, 1);
Move Stand_R_Foot_Back(&R_Foot_Back, 89, 50, 1);
Move Stand_L_Foot_Back(&L_Foot_Back, 88, 50, 1);
Move array_Stand[10] = { Stand_R_Hip, Stand_L_Hip, Stand_R_Upper_Knee, Stand_L_Upper_Knee, Stand_R_Under_Knee, Stand_L_Under_Knee, Stand_R_Foot_Front, Stand_L_Foot_Front, Stand_R_Foot_Back, Stand_L_Foot_Back };
Movement Stand(array_Stand, 10);



Move BendKnees_R_Hip(&R_Hip, 90, 50, 1);
Move BendKnees_L_Hip(&L_Hip, 88, 50, 1);
Move BendKnees_R_Upper_Knee(&R_Upper_Knee, 165, 50, 1);
Move BendKnees_L_Upper_Knee(&L_Upper_Knee, 10, 50, 1);
Move BendKnees_R_Under_Knee(&R_Under_Knee, 0, 50, 1);
Move BendKnees_L_Under_Knee(&L_Under_Knee, 170, 50, 1);
Move BendKnees_R_Foot_Front(&R_Foot_Front, 92, 50, 1);
Move BendKnees_L_Foot_Front(&L_Foot_Front, 88, 50, 1);
Move BendKnees_R_Foot_Back(&R_Foot_Back, 92, 50, 1);
Move BendKnees_L_Foot_Back(&L_Foot_Back, 88, 50, 1);
Move array_BendKnees[10] = { BendKnees_R_Hip, BendKnees_L_Hip, BendKnees_R_Upper_Knee, BendKnees_L_Upper_Knee, BendKnees_R_Under_Knee, BendKnees_L_Under_Knee, BendKnees_R_Foot_Front, BendKnees_L_Foot_Front, BendKnees_R_Foot_Back, BendKnees_L_Foot_Back };
Movement BendKnees(array_BendKnees, 10);



void setup() {

  Serial.begin(115200);
  delay(5000);
   servo.attach(ServoPin);
 
}

void loop() {
 
  Serial.print("stand: ");
 Stand.execute();
 Serial.println(Stand.check_Movement());
 Serial.print("bend: ");
 BendKnees.execute();
 Serial.println(BendKnees.check_Movement());
}
