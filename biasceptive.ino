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
const int numberOfContraceptivesFemale = 16;
const int numberOfContraceptivesMale = 2;
float contraceptionProbabilitiesFemale[numberOfContraceptivesFemale];
float contraceptionProbabilitiesMale[numberOfContraceptivesMale];

UltraSonic ultraSonicSensor(triggerPin, echoPin, sensitivity);
RandomServo servoFemale(servoPinFemale);
RandomServo servoMale(servoPinMale);

void setup() {
  Serial.begin(9600);
  
  //set up all contraception probabilities
  contraceptionProbabilitiesFemale[0] = 0.01;  // chemische Verhuetungsmittel - estimation
  contraceptionProbabilitiesFemale[1] = 0.06;  // Hormonspirale - estimation
  contraceptionProbabilitiesFemale[2] = 0.1;   // Kupferspirale  - estimation
  contraceptionProbabilitiesFemale[3] = 0.12;  // Minipille  - estimation
  contraceptionProbabilitiesFemale[4] = 0.01;  // Verhuetungskappe  - estimation
  contraceptionProbabilitiesFemale[5] = 0.01;  // Verhuetungspflaster - estimation
  contraceptionProbabilitiesFemale[6] = 0.03;  // Vaginalring - Profamilia
  contraceptionProbabilitiesFemale[7] = 0.02;  // Sterilisation - Profamilia
  contraceptionProbabilitiesFemale[8] = 0.5;   // Pille - Profamilia
  contraceptionProbabilitiesFemale[9] = 0.05;  // Kupferkette - estimation
  contraceptionProbabilitiesFemale[10] = 0.01; // Hormonstaebchen - estimation
  contraceptionProbabilitiesFemale[11] = 0.03; // Fruchtbarkeitswahrnehmung - Profamilia
  contraceptionProbabilitiesFemale[12] = 0.01; // Femidom - estimation
  contraceptionProbabilitiesFemale[13] = 0.01; // Diaphragma - Profamilia
  contraceptionProbabilitiesFemale[14] = 0.02; // Depotspritze - Profamilia
  contraceptionProbabilitiesFemale[15] = 0.01; // Kupferball - estimation
  
  contraceptionProbabilitiesMale[0] = 0.97; // Kondom - estimation
  contraceptionProbabilitiesMale[1] = 0.03; // Vasektomie - BZgA
  
  servoFemale.begin();
  servoMale.begin();
}

void loop() {
  int distance = ultraSonicSensor.measure();
  bool activated = ultraSonicSensor.movementDetected();
  if (activated) {
    servoFemale.randomMovement();
    servoFemale.choose(contraceptionProbabilitiesFemale, numberOfContraceptivesFemale);
    
    servoMale.randomMovement();
    servoMale.choose(contraceptionProbabilitiesMale, numberOfContraceptivesMale);
    delay(1000);
  }
}
