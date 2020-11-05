/*
* Enhance the Servo Motor to perform random movements.
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
  /* Create the appearance of a random, calibrating movement.
  * 
  * Move the servo by its full range for up to four times.
  */
  int n = random(1,4);
  for (size_t i = 0; i < n; i++) {
    servo.write(0);
    delay(400);
    servo.write(180);
    delay(400);
  }

}

void RandomServo::choose(float* contraceptionProbabilities, int numberOfProbabilities)
{
  /* Move the servo to a position based on a given list of probabilities.
  *
  * float* contraceptionProbabilities: A list of probabilities, the probabilities should add up to 100
  * int numberOfProbabilities: The length of the list.
  */
  int targetProbability = random(1,100);
  float lower = 0;
  float upper = contraceptionProbabilities[0]*100;
  bool whithinRange = (targetProbability > lower && targetProbability <= upper);
  int i = 0;
  while ( whithinRange == false) {
    lower = upper;
    if (i < numberOfProbabilities-1) {
      upper += contraceptionProbabilities[i+1]*100;
    }

    whithinRange = (targetProbability > lower && targetProbability <= upper);
    i++;  
  }

  // i is the index of the entry in contraceptionProbabilities, which was selected
  // The method assumes, there will be as many positions as there are probabilities
  // and that the probabilities have an equal amount of positions reserved on e.g. a scale
  float position = 180*i/numberOfProbabilities + 180/numberOfProbabilities/2;
  servo.write(position);
}
