// stage 2: one raw ADC sample per second. Showed ~74 counts of spread.
void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(32);
  Serial.println(raw);
  delay(1000);
}
