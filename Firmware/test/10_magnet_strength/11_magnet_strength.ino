#include <AS5600.h>

#include <Wire.h>


AS5600L as5600;
#define AS5600_MD (1 << 5)   // Magnet detected
#define AS5600_ML (1 << 4)   // Magnet too weak
#define AS5600_MH (1 << 3)   // Magnet too strong
void setup() {
  Serial.begin(115200);
  while (!Serial);

  Wire.begin();

  // Set correct I2C address if needed (common for AS5600L)
  as5600.setAddress(0x36);   // change to 0x36 if required
  as5600.begin();

  Serial.println("AS5600L Magnet Status Check");
}

void loop() {
  uint8_t status = as5600.readStatus();

  Serial.print("Status bits: ");
  Serial.println(status, BIN);

  if (status & AS5600_MD) {
    Serial.println("✔ Magnet detected");

    if (status & AS5600_ML) {
      Serial.println("⚠ Magnet too weak (too far)");
    }
    else if (status & AS5600_MH) {
      Serial.println("⚠ Magnet too strong (too close)");
    }
    else {
      Serial.println("✔ Magnet strength OK");
    }

  } else {
    Serial.println("✖ No magnet detected");
  }

  Serial.println("---------------------------");
  delay(1000);
}
