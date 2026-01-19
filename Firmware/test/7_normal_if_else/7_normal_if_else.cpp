#include <AccelStepper.h>

#define EN_PIN 8
#define POS_1 A0

int target_angle = 0;
bool motor_active = false;
AccelStepper stepper_1(AccelStepper:: DRIVER, 2,5);

const int DEAD_BAND = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  stepper_1.setMaxSpeed(1000);
  stepper_1.setAcceleration(800);

  pinMode(EN_PIN, OUTPUT);
  pinMode(POS_1, INPUT);

  digitalWrite(EN_PIN, LOW);
}

int get_current_angle(int pin){
  int raw = analogRead(pin);
  int angle = map(raw, 0, 1023, 0, 250);
  return angle;
}

void move_until_angle(int tar_angle, int pin){
  while (true){
    int curr_angle = get_current_angle(pin);
    int error = tar_angle - curr_angle;
    if (abs(error) < DEAD_BAND){
      break;
    }
    if(error < -DEAD_BAND){
    //Serial.println("Moving AnticlockWise");
    stepper_1.setSpeed(-700);
    stepper_1.runSpeed();
    delay(3);
    }
    if(error > DEAD_BAND){
      //Serial.println("Moving ClockWise");
      stepper_1.setSpeed(700);
      stepper_1.runSpeed();
      delay(3);
    }
  }
}
void move_to_angle(int tar_angle, int pin){
    move_until_angle(tar_angle, pin);
}
void loop() {
  //put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    String input = Serial.readStringUntil('\n');
    target_angle = input.toInt();
    Serial.println(target_angle);
    move_to_angle(target_angle, A0);
  }
}
