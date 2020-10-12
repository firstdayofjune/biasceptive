#include <UltraSonic.h>
#include <RandomServo.h>
#include <Servo.h>


// Assign pins
int triggerPin = 11; // Ultra Sonic - trigger Pin
int echoPin = 12; // Ultra Sonic - echo Pin
int servoPinFemale = 8; // Servo Motor - female contraceptives
int servoPinMale = 9; // Servo Motor - male contraceptives

// Configuration
int sensitivity = 20; // Everything within 20cm will be considered a movement


UltraSonic ultraSonicSensor(triggerPin, echoPin, sensitivity);
RandomServo servoFemale(servoPinFemale);


void setup() {
  Serial.begin(9600);

}

void loop() {
  int distance = ultraSonicSensor.measure();
  bool movement = ultraSonicSensor.movementDetected();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(", Movement: ");
  Serial.println(movement);
  if (movement) {
    servoFemale.randomMovement();
    delay(10000);
  }
}
