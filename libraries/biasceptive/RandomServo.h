#ifndef RandomServo_h
#define RandomServo_h

#include "Arduino.h"
#include <Servo.h>

class RandomServo
{
  public:
    RandomServo(int servoPin);
    void begin();
    void randomMovement();
    void choose(float* contraceptionProbabilities, int numberOfProbabilities);
  private:
    int _servoPin;
    Servo servo;
};

#endif
