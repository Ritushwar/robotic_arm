int pos_x = A0;
int value = 0;
int angle = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pos_x, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pos_x);
  angle = map(value,0,1023,0,250);
  Serial.println(angle);
  delay(1000);
}
