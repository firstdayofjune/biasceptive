/*
*
* 
*
*/
#include "Arduino.h"
#include "UltraSonic.h"

UltraSonic::UltraSonic(int triggerPin, int echoPin, int sensitivity)
{
  _triggerPin = triggerPin;
  _echoPin = echoPin;
  _sensitivity = sensitivity;

  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

int UltraSonic::measure()
{
  /* Measure the distance using the ultrasonic sensor
  *
  * Credits for this method goes to from https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
  * Returns:
  *   int 
  */
  long duration = 0;
  int distance = 0;
  // Clears the _triggerPin
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the _triggerPin on HIGH state for 10 micro seconds
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_triggerPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(_echoPin, HIGH);
  // Calculating the distance
  distance = duration*0.034/2;
  return distance;
}

bool UltraSonic::movementDetected()
{
  int distance = measure();
  if (distance <= _sensitivity) {
    return true;
  }
  return false;
}

