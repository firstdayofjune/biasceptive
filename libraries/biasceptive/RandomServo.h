#ifndef RandomServo_h
#define RandomServo_h

#include "Arduino.h"
#include <Servo.h>

class RandomServo
{
  public:
    RandomServo(int servoPin);
    void randomMovement();
  private:
    int _servoPin;
    Servo servo;
};

#endif