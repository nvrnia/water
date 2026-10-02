// water / node v1 (breadboard)
// Reads one capacitive soil sensor every 30 min, keeps 3 weeks in RAM,
// serves the history as CSV over HTTP on the local network.
//
// Wiring: sensor VCC -> 3V3, GND -> GND, AOUT -> GPIO 32 (ADC1)
// Known limits: history is lost on reboot; no reset-reason logging yet.

#include <WiFi.h>
#include <time.h>
#include "secrets.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASS;

WiFiServer server(80);

const int SENSOR_PIN = 32;              // ADC1, keeps working while Wi-Fi is on
const int MAX_READINGS = 1008;          // 21 days at 30 min
int readings[MAX_READINGS];
unsigned long stamps[MAX_READINGS];
int count = 0;                          // how many slots hold data
int nextSlot = 0;                       // where the next reading goes

unsigned long lastReading = 0;
const unsigned long INTERVAL = 1800000UL;   // 30 min in ms

// 64 samples, 2 ms apart, averaged. Cut the spread from 74 to 4 counts.
int readSensor() {
  long total = 0;
  for (int i = 0; i < 64; i++) {
    total = total + analogRead(SENSOR_PIN);
    delay(2);
  }
  return total / 64;
}

// circular buffer: the pointer wraps, the data never moves
void storeReading() {
  readings[nextSlot] = readSensor();
  stamps[nextSlot] = time(nullptr);
  nextSlot = (nextSlot + 1) % MAX_READINGS;
  if (count < MAX_READINGS) count++;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("starting");

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  WiFi.begin(ssid, password);

  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries < 40) {
    delay(500);
    Serial.print(".");
    tries++;
  }
  Serial.println("");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("wifi failed, status = ");
    Serial.println(WiFi.status());
    return;
  }
  Serial.println(WiFi.localIP());

  // real time from the internet; CET/CEST with automatic DST
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
  tzset();
  while (time(nullptr) < 1700000000) delay(500);

  server.begin();
  storeReading();
  lastReading = millis();
}

void loop() {
  // non-blocking timing: check the clock instead of delay(), so the
  // board can answer web requests between readings
  if (millis() - lastReading >= INTERVAL) {
    storeReading();
    lastReading = millis();
  }

  WiFiClient client = server.available();
  if (!client) return;

  while (client.available()) client.read();

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/plain");
  client.println("");
  client.print("readings stored: ");
  client.println(count);
  client.println("");

  int start = (nextSlot - count + MAX_READINGS) % MAX_READINGS;   // oldest
  for (int i = 0; i < count; i++) {
    int idx = (start + i) % MAX_READINGS;
    time_t ts = stamps[idx];
    struct tm t;
    localtime_r(&ts, &t);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", &t);
    client.print(buf);
    client.print(",");
    client.println(readings[idx]);
  }
  client.stop();
}
