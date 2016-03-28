#include <Arudino.h>
#include <Servo.h>

// define turn
#define RIGHT 1
#define LEFT -1


// declare servo objects
Servo leftServo;
Servo rightServo;

const byte power = 250;

// function for stopping vehicle
void stop (int time = 500) // stop device for 500ms then exec next command
{
    leftServo.writeMicroseconds(1500);
    rightServo.writeMicroseconds(1500);
    delay(time);
}

// function for moving forward
void forward()
{
    leftServo.writeMicroseconds(1500+power);
    rightServo.writeMicroseconds(1500-power);
}

// function for moving in time
void forwardTime(unsigned int time)
{
    forward();
    delay(time);
    stop();

}


// function for right turn
void turn(int direction, int time)
{
    leftServo.writeMicroseconds(1500+power*direction);
    rightServo.writeMicroseconds(1500+power*direction);
    // delay(time);
    delay(time);
    stop(); // will stop device for 500ms as defined in stop function
}
