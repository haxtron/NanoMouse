#include <Servo.h>

const byte ledPin = 13; // def led port
const byte buttonPin = 9; // def button port


void setup() {
    // attach servos to pin
    leftServo.attach(6);
    rightServo.attach(5);

    pinMode(ledPin,OUTPUT);  // status on 13 pin
    pinMode(buttonPin,INPUT_PULLUP); // connecting button with internal resistor

  while(digitalRead(buttonPin))
  {} // do nothing till button is pressed

  // turning
  turn(LEFT,500);
  turn(RIGHT,500);

}

void loop() {
  digitalWrite(ledPin,HIGH); // blink led when button is pressed

}
