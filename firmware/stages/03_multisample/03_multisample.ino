// stage 3: average 64 samples. Spread dropped from 74 to 4 counts.
void setup() {
  Serial.begin(115200);
}

void loop() {
  long total = 0;
  for (int i = 0; i < 64; i++) {
    total = total + analogRead(32);
    delay(2);
  }
  int average = total / 64;
  Serial.println(average);
  delay(1000);
}
