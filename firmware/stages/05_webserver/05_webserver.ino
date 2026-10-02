// stage 5: answer a browser with the current reading.
// Reactive only: measures when asked, keeps no history.
#include <WiFi.h>
#include "secrets.h"

WiFiServer server(80);

int readSensor() {
  long total = 0;
  for (int i = 0; i < 64; i++) {
    total = total + analogRead(32);
    delay(2);
  }
  return total / 64;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("starting");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries < 40) {
    delay(500);
    Serial.print(".");
    tries++;
  }
  Serial.println("");
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("failed, status = ");
    Serial.println(WiFi.status());
    return;
  }
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.available()) client.read();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/plain");
    client.println("");
    client.println(readSensor());
    client.stop();
  }
}
