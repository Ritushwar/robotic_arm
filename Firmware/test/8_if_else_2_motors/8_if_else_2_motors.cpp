#include <AccelStepper.h>

#define EN_PIN 8
#define POS_1 A0

int target_angle = 0;
bool motor_active = false;
AccelStepper stepper_1(AccelStepper:: DRIVER, 2,5);   // for x-axis
AccelStepper stepper_2(AccelStepper:: DRIVER, 3,6);   // for y-axis

const int DEAD_BAND = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  stepper_1.setMaxSpeed(1000);
  stepper_1.setAcceleration(800);

  stepper_2.setMaxSpeed(1000);
  stepper_2.setAcceleration(800);

  pinMode(EN_PIN, OUTPUT);
  pinMode(POS_1, INPUT);

  digitalWrite(EN_PIN, LOW);
}

int get_current_angle(int pin){
  int raw = analogRead(pin);
  int angle = map(raw, 0, 1023, 0, 250);
  return angle;
}


void update_motor(AccelStepper &stepper, int pin, int tar_position){
  int curr_position = get_current_angle(pin);
  int error = tar_position - curr_position;

  if (abs(error) < DEAD_BAND){
    stepper.setSpeed(0);
    return;
  }
  if(error > DEAD_BAND){
    stepper.setSpeed(700);
  }else{
    stepper.setSpeed(-700);
  }
  stepper.runSpeed();
}
void loop() {
  //put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String input = Serial.readStringUntil('\n');
    target_angle = input.toInt();
    Serial.println(target_angle);
  }
  update_motor(stepper_1, A0, target_angle);
  update_motor(stepper_2, A0, target_angle);
}
