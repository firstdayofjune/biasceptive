#ifndef UltraSonic_h
#define UltraSonic_h

#include "Arduino.h"

class UltraSonic
{
  public:
    UltraSonic(int triggerPin, int echoPin, int sensitivity);
    int measure();
    bool movementDetected();
  private:
    int _triggerPin;
    int _echoPin;
    int _sensitivity;
};

#endif