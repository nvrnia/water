// stage 1: prove the toolchain. Compile, upload, see text come back.
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("hello");
  delay(1000);
}
