static bool last_condition = false;
bool led_status = false;
int led_pin = A3;
int data = 77;
void setup() {
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd.startsWith("Data:")) {
      data = cmd.substring(5).toInt();
      //Serial.print("Received Data: ");
      //Serial.println(data);
    }
    bool current_condition = (data < 20);
    if(current_condition && !last_condition){
      led_status = !led_status;
      digitalWrite(led_pin, led_status ? HIGH : LOW);
      //Serial.println(led_status ? "LED ON" : "LED OFF");
    }
    last_condition = current_condition;
  } 
}
