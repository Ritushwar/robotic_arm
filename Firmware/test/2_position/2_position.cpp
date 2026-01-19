#include <AccelStepper.h>
#define EN_PIN 8
int steps;
AccelStepper stepper(AccelStepper::DRIVER, 2, 5);
int steps_per_degrees = 1;
int target_degrees = 90;
int target_steps = steps_per_degrees * target_degrees;

void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(900);
  stepper.setAcceleration(500);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0){
    String input = Serial.readStringUntil('\n');
    steps = input.toInt();
    Serial.println(steps);
    if(steps < 0){
      stepper.moveTo(steps);
      stepper.runToPosition();
      delay(1000);
      steps = 0;
    }
    else{
      stepper.moveTo(steps);
      stepper.runToPosition();
      delay(1000);
      steps = 0;
    }
  }
}
