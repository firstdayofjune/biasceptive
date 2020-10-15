#include <UltraSonic.h>
#include <RandomServo.h>
#include <Servo.h>


// Assign pins
int triggerPin = 11; // Ultra Sonic - trigger Pin
int echoPin = 12; // Ultra Sonic - echo Pin
int servoPinFemale = 8; // Servo Motor - female contraceptives
int servoPinMale = 6; // Servo Motor - male contraceptives

// Configuration
int sensitivity = 20; // Everything within 20cm will be considered a movement
const int numberOfContraceptionsFem = 16;
const int numberOfContraceptionsMale = 2;
float contraceptionProbabilityFem[numberOfContraceptionsFem];
float contraceptionProbabilityMale[numberOfContraceptionsMale];



UltraSonic ultraSonicSensor(triggerPin, echoPin, sensitivity);
RandomServo servoFemale(servoPinFemale);
RandomServo servoMale(servoPinMale);


void setup() {
  Serial.begin(9600);
  
  //set up all contraception probabilities
    contraceptionProbabilityFem[0] = 0.01;
    contraceptionProbabilityFem[1] = 0.01;
    contraceptionProbabilityFem[2] = 0.01;
    contraceptionProbabilityFem[3] = 0.01;
    contraceptionProbabilityFem[4] = 0.03;
    contraceptionProbabilityFem[5] = 0.01;
    contraceptionProbabilityFem[6] = 0.05;
    contraceptionProbabilityFem[7] = 0.5;
    contraceptionProbabilityFem[8] = 0.01;
    contraceptionProbabilityFem[9] = 0.01;
    contraceptionProbabilityFem[10] = 0.01;
    contraceptionProbabilityFem[11] = 0.01;
    contraceptionProbabilityFem[12] = 0.12;
    contraceptionProbabilityFem[13] = 0.1;
    contraceptionProbabilityFem[14] = 0.1;
    contraceptionProbabilityFem[15] = 0.01;
    
    contraceptionProbabilityMale[0] = 0.98;
    contraceptionProbabilityMale[1] = 0.02;
  
  
  //servoFemale.begin();
  servoMale.begin();

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
    servoFemale.choose(contraceptionProbabilityFem,numberOfContraceptionsFem);

    servoMale.randomMovement();
    servoMale.choose(contraceptionProbabilityMale,numberOfContraceptionsMale);
    Serial.print("fertig");
    delay(1000);
  }
}
