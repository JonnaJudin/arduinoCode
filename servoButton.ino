#include <Servo.h>

Servo myServo;
int switchState = 0;
int const ANGLE = 90;

void setup() {
  // Switch connected to 2
  pinMode(2, INPUT);
  // Servo connected to 9
  myServo.attach(9);
}

void loop() {
  // Check if switch pushed
  switchState = digitalRead(2);
  if (switchState == LOW) {
    delay(250);
  }
  else {
    myServo.write(ANGLE); // turn the servo
    delay(2000); // wait 2 sec
    myServo.write(0); // return to initial position
  }
}
