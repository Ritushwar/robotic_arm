#include <AccelStepper.h>
#define EN_PIN 8
AccelStepper stepper_1(AccelStepper::DRIVER, 2, 5);   // step, dir for x-axis
AccelStepper stepper_2(AccelStepper::DRIVER, 3, 6);    // step, dir for y-axis

void setup() {
  stepper_1.setMaxSpeed(1000);
  stepper_2.setMaxSpeed(1000);
  stepper_1.setAcceleration(800);
  stepper_2.setAcceleration(800);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);
}

void loop() {
  stepper_1.moveTo(400);
  stepper_2.moveTo(800);
  while(stepper_1.distanceToGo() != 0 || stepper_2.distanceToGo() != 0){
    stepper_1.run();
    stepper_2.run();
  }
  delay(1000);

  stepper_1.moveTo(0);
  stepper_2.moveTo(0);
  while(stepper_1.distanceToGo() != 0 || stepper_2.distanceToGo() != 0){
    stepper_1.run();
    stepper_2.run();
  }
  delay(1000);
}
