int touch_pin = 4;
int data = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(touch_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = touchRead(touch_pin);
  Serial.print("Data:");
  Serial.println(data);
  delay(100);
}
