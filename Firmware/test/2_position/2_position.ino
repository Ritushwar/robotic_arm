#include <AccelStepper.h>
#define EN_PIN 8
AccelStepper stepper(AccelStepper::DRIVER, 2, 5);
int steps_per_degrees = 1;
int target_degrees = 90;
int target_steps = steps_per_degrees * target_degrees;

void setup() {
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(300);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);
}

void loop() {
  stepper.moveTo(200);
  stepper.runToPosition();
  delay(1000);

  stepper.moveTo(0);
  stepper.runToPosition();
  delay(1000);
}
