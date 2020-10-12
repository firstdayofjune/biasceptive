/*
*
* 
*
*/
#include "Arduino.h"
#include "RandomServo.h"
#include <Servo.h>

RandomServo::RandomServo(int servoPin)
{
  _servoPin = servoPin;
  Servo servo;
  servo.attach(servoPin);
}

void RandomServo::randomMovement()
{
	servo.write(0);
    delay(1000);
    servo.write(180);
    delay(1000);
}