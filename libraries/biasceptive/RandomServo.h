#ifndef RandomServo_h
#define RandomServo_h

#include "Arduino.h"
#include <Servo.h>

class RandomServo
{
  public:
    RandomServo(int servoPin);
    void randomMovement();
    void begin();
    void choose(float* contraceptionProbability, int numberOfProbabilities);
  private:
    int _servoPin;
    Servo servo;
    //float* _contraceptionProbability;


};

#endif
