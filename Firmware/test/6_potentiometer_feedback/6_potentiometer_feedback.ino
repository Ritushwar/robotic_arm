#include <AccelStepper.h>
#include<math.h>
#define EN_PIN 8
AccelStepper stepper_1(AccelStepper::DRIVER, 2, 5);   // step, dir for x-axis
#define pos_1 A0    // to read the angular position of stepper_1

void setup() {
  stepper_1.setMaxSpeed(1000);
  stepper_1.setAcceleration(800);

  pinMode(EN_PIN, OUTPUT);
  pinMode(pos_1, INPUT);
  Serial.begin(9600);

  digitalWrite(EN_PIN, LOW);
}

int get_curr_position(int pos){
  // read the position of each joints using potentiometer
  int raw = analogRead(pos);
  int angle = map(raw,0,1023, 0, 180);
  return angle;
}

int angle_to_steps(float angle){
  // angle to step converter
  return ceil(angle / 1.8f);     // floating division
}

void move_both(int tar_ang_1){
  // move one motor using the feedback from the potentiometer
  while(true){
    int curr_ang_1 = get_curr_position(pos_1);
    int error = tar_ang_1 - curr_ang_1;
    Serial.println(curr_ang_1);

    if(abs(error) <=2 ){
      stepper_1.setSpeed(0);    // stop the motor
      return;
    }

    if(error>0){
      stepper_1.setSpeed(400);  // move forward
    }
    else{
      stepper_1.setSpeed(-400);  // move backward
    }
    stepper_1.runSpeed();       // continuos rotation
  }
}
void loop() {
  move_both(100);     // give value in angle
  delay(1000);
}


// this make the motor move forward and backward when the potentiometer reading is the range of 15 to 45.

