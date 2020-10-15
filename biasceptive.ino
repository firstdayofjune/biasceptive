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
    contraceptionProbabilityFem[0] = 0.01;  // chem. VM - estimation
    contraceptionProbabilityFem[1] = 0.06;  // Hormonspirale - estimation
    contraceptionProbabilityFem[2] = 0.1;   // Kupferspirale  - estimation
    contraceptionProbabilityFem[3] = 0.12;  // Minipille  - estimation
    contraceptionProbabilityFem[4] = 0.01;  // Verhütungskappe  - estimation
    contraceptionProbabilityFem[5] = 0.01;  // Verhütungspflaster - estimation
    contraceptionProbabilityFem[6] = 0.03;  // Vaginalring - Profamilia
    contraceptionProbabilityFem[7] = 0.02;  // Sterilisation - Profamilia
    contraceptionProbabilityFem[8] = 0.5;   // Pille - Profamilia
    contraceptionProbabilityFem[9] = 0.05;  // Kupferkette - estimation
    contraceptionProbabilityFem[10] = 0.01; // Hormonstäbchen - estimation
    contraceptionProbabilityFem[11] = 0.03; // Fruchtbarkeitswahrnehmung - Profamilia
    contraceptionProbabilityFem[12] = 0.01; // Femidom - estimation
    contraceptionProbabilityFem[13] = 0.01; // Diaphragma - Profamilia
    contraceptionProbabilityFem[14] = 0.02; // Depotspritze - Profamilia
    contraceptionProbabilityFem[15] = 0.01; // Kupferball - estimation
    
    contraceptionProbabilityMale[0] = 0.03; // Vasektomie - BZgA
    contraceptionProbabilityMale[1] = 0.97; // Kondom - estimation
  
  
  servoFemale.begin();
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
    delay(1000);
  }
}
