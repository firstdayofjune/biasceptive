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

}

void RandomServo::begin(){
    servo.attach(_servoPin);
}
void RandomServo::randomMovement()
{
  int n = random(1,4);
  for (size_t i = 0; i < n; i++) {
    servo.write(0);
    delay(400);
    servo.write(180);
    delay(400);
  }

}

void RandomServo::choose(float* contraceptionProbability,int numberOfProbabilities)
{

    int targetProbability = random(1,100);
    float lower = 0;
    float upper = contraceptionProbability[0]*100;
    bool whithinrange = (targetProbability > lower && targetProbability <= upper);
    int i = 0;
    while ( whithinrange == false) {
      lower = upper;
      if (i < numberOfProbabilities-1) {
        upper += contraceptionProbability[i+1]*100;
      }

      whithinrange = (targetProbability > lower && targetProbability <= upper);
      i++;
    }

    float position = 180*i/numberOfProbabilities + 180/numberOfProbabilities/2;
    servo.write(position);



}
