#include <Servo.h>
Servo ESC;
int Gaspedal;
int LastSpeed = 0;
int CurrentSpeed = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing Buggy-Booster..."); 
  ESC.attach(9, 1000, 2000);
  ESC.write(CurrentSpeed);
} 

void loop() {
  Gaspedal = analogRead(A0);
  CurrentSpeed = map(Gaspedal, 175, 870, 0, 180);

  if(CurrentSpeed > 175) {
    CurrentSpeed = 180;
  } else if(CurrentSpeed < 20){
    CurrentSpeed = 0;
  }

  
  int difference = LastSpeed - CurrentSpeed;
  if(difference < 0) {
    difference = difference * -1;
  }

  if(difference > 1) {
    Serial.println(CurrentSpeed);
    ESC.write(CurrentSpeed);
  }
 
  delay(100);
  LastSpeed = CurrentSpeed;
}
