# logbook

## early Sep — requirements

- 4 plants now, maybe 10 within a year. All in one room, roughly one per corner, ~4 m apart. Mains everywhere, Wi-Fi in the room
- wanted: reading on my (Android) phone, a notification when a plant is dry, easy to add plants. Tidy and permanent at the end
- budget about €300. No programming experience at the start

## early Sep — architecture and parts

- one Wi-Fi node per cluster of plants instead of one central box with long sensor cables. Short analog wires, and a new plant is just a new node
- capacitive sensors, ESP32 DevKit V1, own firmware in C++. Reasons in [decisions.md](decisions.md)
- found that ADC2 stops working once Wi-Fi is on, so only the ADC1 pins (GPIO 32–36 and 39 on this board) can read sensors
- two different boards are sold as "capacitive soil moisture sensor v1.2". The ME555 one only runs on 5 V. Bought the TL555I version with a regulator

## 2026-09-12? — first measurements

- [experiment 0](experiments/00-sensor-output.md): output is 2.70 V in air and 1.00 V in water. I predicted 0 V in air and higher in water, so the direction was opposite to my guess
- first attempt read a steady 1.97 V that didn't change in water. The sensor's ground wasn't connected. Found it by measuring between two points that should read 0 V ([problems](problems.md#floating-ground))
- soil: 2.66 V after 3–4 weeks without water, 1.09 V after overwatering
- toolchain working: Arduino IDE, COM5, board answers over serial
- [noise](experiments/01-noise-averaging.md): single ADC samples spread 74 counts; averaging 64 brings it to 4
- Wi-Fi and a small web server; reading visible on my phone
- [power supply](experiments/03-power-supply.md) and [temperature](experiments/04-temperature.md) checks: no effect above the noise

## 2026-09-13 to 19 — first drying run

- node logs every 30 min with real timestamps (NTP) into a 3-week buffer
- [drying curve](experiments/02-soil-drying.md): 1289 → 1535 counts in 6 days, rate slowing from 55 to 24 per day
- node restarted 6 times; each restart wiped the buffer. Cause unknown

## 2026-09-24 — review

- sensor A in air through the ADC: 3279. Air and overwatered soil become the calibration anchors
- watering threshold set to the midpoint, 2239, as a starting guess
- pot was sitting in a saucer full of water, so it couldn't drain. Explains the slow drying
- the probe covers most of a 4-inch pot. In a foot-deep pot it would only see the top
- decided: perfboard, sensors powered from a GPIO only while sampling, KiCad for the schematic

## 2026-10-02 — half-depth probe

- readings came back at ~3170, nearly air. Probe was only half in the soil after the 24 Sep air test ([problems](problems.md#half-depth-probe))
- data from that period discarded
- decided: Home Assistant on a Raspberry Pi for history, graphs and notifications. JST-XH plug-in sensors, ESP32 in female headers
- started this repo
