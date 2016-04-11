#include <Servo.h>

Servo leftServo;
Servo rightServo;

void setup()
{
    leftServo.attach(6);
    rightServo.attach(5);

    Serial.begin(9600);
}

void loop()
{
    bool msgReceived = false;
    char msg[2]; // for the left and right motor

    while(!msgReceived)
    {
        while(Serial.available())
        {
            Serial.readBytes(msg,2);
            msgReceived = true;
        }
    }

    leftServo.writeMicroseconds(1500+msg[0] * 2);
    rightServo.writeMicroseconds(1500-msg[1] * 2);
}

