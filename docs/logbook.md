# Logbook

## 2026-09 (early)

I set the requirements, picked the architecture and ordered parts.

- I have 4 plants now and expect about 10 within a year.
- They're in one room, about 4 m apart, one per corner.
- Every plant has mains nearby, and the room has Wi-Fi.
- I wanted the reading on my Android phone, a notification when a plant is dry, and easy expansion.
- The budget was about €300. I hadn't programmed before.
- I went with one Wi-Fi node per cluster of plants instead of one central box. Analog wires stay short, and a new plant means a new node.
- ADC2 stops working while Wi-Fi is on. Only the ADC1 pins can read sensors, which on this board are GPIO 32 to 36 and 39.
- Two different boards are sold as "capacitive soil moisture sensor v1.2". The ME555 one only runs on 5 V, so I bought the TL555I version with a regulator.

Next: measure the sensor output before connecting it to the ESP32.

## 2026-09-12?

I measured both sensors and got the first readings over Wi-Fi.

- The first attempt read a steady 1.97 V in air and in water. The sensor's ground wire wasn't connected ([problems](problems.md)).
- Sensor output was 2.70 V in air and 1.00 V in water ([experiment 0](experiments/00-sensor-output.md)). My prediction was wrong. I expected 0 V in air and a higher value in water.
- In the pot, sensor A read 2.66 V after 3 to 4 weeks without water and 1.09 V after overwatering.
- Single ADC samples spread over 74 counts. Averaging 64 samples brought that down to 4 ([experiment 1](experiments/01-noise-averaging.md)).
- The node joined Wi-Fi and served the reading to my phone.
- Swapping laptop USB for a phone charger changed nothing ([experiment 3](experiments/03-power-supply.md)).
- Opening the window moved the reading 3 to 5 counts ([experiment 4](experiments/04-temperature.md)).

Next: log a reading every 30 min with real timestamps.

## 2026-09-13

I started the first drying run, 13 to 19 Sep.

- The node logs every 30 min with NTP timestamps into a 21-day buffer.
- Over 6 days the reading went from 1289 to 1535 (16% dry). The rate slowed from 55 to 24 counts per day ([experiment 2](experiments/02-soil-drying.md)).
- The node restarted 6 times, and each restart wiped the buffer. The cause is unknown so far.

Next: measure sensor A in air through the ADC.

## 2026-09-24

- Sensor A in air through the ADC read 3279. Air (3279) and overwatered soil (1199) became the calibration anchors.
- I set the watering threshold to the midpoint, ADC 2239 (50%), as a starting guess.
- The pot was standing in a saucer full of water, so it couldn't drain. That explains the slow drying.
- The probe covers most of a 4-inch pot. In a foot-deep pot it would only reach the top.
- I chose perfboard, GPIO-switched sensor power and KiCad for the schematic.

Next: coat the sensors.

## 2026-10-02

- The reading came back at about 3170, close to the air value. The probe was only half in the soil after the air reading on 24 Sep ([problems](problems.md)).
- I discarded the readings from that period.
- I chose Home Assistant on a Raspberry Pi for history, graphs and notifications.
- Sensors will plug in with JST-XH connectors, and the ESP32 will sit in female headers.
- I started this repo.

Next: measure sensor B through the ADC before coating it.
