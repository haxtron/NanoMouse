#include <Arduino.h>
#include <Servo.h>

// define turn
#define RIGHT 1
#define LEFT -1


// define class
class NanoMouseMotors {
  private: // cannot be accessed outside of the class

    // declare servo objects
    Servo leftServo;
    Servo rightServo;

    static const byte power = 100; /* static allows to store variable even after function was called second or more time
   need to be when define class... */

  public: // can be accessed outside of the class

    void attach(byte leftMotor, byte rightMotor) {
      // attach servos to pin
      leftServo.attach(leftMotor);
      rightServo.attach(rightMotor);
    }

    // function for moving forward
    void forward()
    {
      leftServo.writeMicroseconds(1500 + power);
      rightServo.writeMicroseconds(1500 - power);
    }

    // function for stopping vehicle
    void stop (int time = 200) // stop device for 200ms then exec next command
    {
      leftServo.writeMicroseconds(1500);
      rightServo.writeMicroseconds(1500);
      delay(time);
    }

    // function for moving in time
    void forwardTime(unsigned int time)
    {
      forward();
      delay(time);
      stop();

    }

    // function for right turn
    void turn(int direction, int degrees)
    {
      leftServo.writeMicroseconds(1500 + power * direction);
      rightServo.writeMicroseconds(1500 + power * direction);
      // delay(time);
      delay(round(4.5749 * degrees + 6.2313));
      stop(); // will stop device for 200ms as defined in stop function
    }

    void polygon(unsigned int time, int sides)
    {
      for (int i = 0; i < sides; i++)
      {
        forwardTime(time);
        turn(RIGHT, 360 / sides);
      }

    }



};
