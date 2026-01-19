#include <AccelStepper.h>
#define EN_PIN 18
AccelStepper stepper(AccelStepper::DRIVER, 2, 5);

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(400);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);
}

void loop() {
  stepper.setSpeed(600);
  stepper.runSpeed();
}
