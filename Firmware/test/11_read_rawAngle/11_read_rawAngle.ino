// read raw angle value from as5600L at address 0x36
#include <AS5600.h>
#include<Wire.h>

AS5600L as5600;

void setup(){
  Serial.begin(115200);
  while(!Serial);

  Wire.begin();
  as5600.setAddress(0x36);
  as5600.begin();
  Serial.println("Reading Angle value from AS5600L");
}
void loop(){
  uint16_t rawAngle = as5600.readAngle();
  Serial.print("Raw Angle value: ");
  Serial.print(rawAngle);

  // Convert to degree
  float angleDeg = rawAngle * 360.0 / 4096.0;

  Serial.print("\t Angle (deg): ");
  Serial.println(angleDeg, 2);

  delay(200);
}