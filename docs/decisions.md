# Decisions

## One Wi-Fi node per plant cluster (2026-09)

Each node reads up to 4 sensors that sit close together. Analog wires stay short, so they pick up less noise. A new plant means a new node, and no cable crosses the room.

Other option: one central controller with long sensor cables, worse for noise, expansion and tidiness.

## Capacitive sensors (2026-09)

A resistive probe passes current through wet soil, which drives electrolysis and corrodes the metal. A capacitive sensor has its electrodes under a coating and passes no current through the soil.

Other option: resistive probes, cheaper but they wear out in the soil.

## ESP32 WROOM DevKit V1 (2026-09)

The board breaks out 6 ADC1 pins (GPIO 32 to 36 and 39), enough for 4 sensors with Wi-Fi on. It also has the most beginner material online.

Other option: the ESP32-C3 has fewer beginner guides, and the ESP8266 has one analog input.

## Sensors on ADC1 pins only (2026-09)

The Wi-Fi driver uses ADC2, so ADC2 can't be read while Wi-Fi is on. Source: Espressif ESP-IDF documentation.

Other option: none while the node needs Wi-Fi.

## No external ADC or amplifier (2026-09)

The 12-bit ADC gives about 2100 steps across the sensor's 1.7 V swing. Soil varies far more than one step.

Other option: an ADS1115 or an op-amp stage, more parts for resolution I can't use.

## No voltage divider on the sensor output (2026-09-12?)

The highest output I measured was 2.70 V, below the ESP32's 3.3 V.

Other option: a divider, only needed if the output went above 3.3 V.

## TL555I sensor with regulator (2026-09)

The retailer lists this version as 3.3 to 5 V in and 0 to 3 V out.

Other option: the ME555 version, which only works on 5 V.

## Own firmware in C++, built in stages (2026-09)

Learning to program was one of the goals. Each stage adds one thing, so a failure has one suspect.

Other option: ESPHome, faster to set up but very little programming.

## 64-sample average (2026-09-12?)

Averaging cut the spread from 74 to 4 counts with no extra parts.

Other option: a 100 nF capacitor on the ADC pin, not needed at this noise level.

## No temperature compensation (2026-09-12?)

Opening the window moved the reading 3 to 5 counts, the same as the noise.

Other option: a temperature sensor and a correction, not worth it for an effect that size.

## Per-sensor calibration with air and water as anchors (2026-09-24)

Sensors and ADCs differ, so each sensor gets its own anchors. Real soil reached about 92% of the air-to-water range, so air and water are close to the real extremes. They're also easy to repeat.

Other option: one calibration for every sensor, which carries each unit's offset into its readings.

## 30-minute sampling (2026-09-12?)

Soil dries over days, and watering changes the reading within minutes. Every 30 min catches both.

Other option: every hour, which would hide watering events.

## Alert at ADC 2239, re-arm at 1800 (2026-09-24)

2239 is the midpoint of the anchors (50%) and a first guess. The second threshold stops noise near the line from sending repeated alerts. I'll tune both against finger checks.

Other option: a single threshold, which would fire again and again near the line.

## Probe pushed in to the line (2026-09-24)

In a 4-inch pot the sensing area covers most of the soil.

Other option: a shallow probe, which only tracks the top layer my finger already checks.

## Perfboard, soldered by hand (2026-09-24)

Perfboard is cheap and quick, and it's enough for two sensors.

Other option: a custom PCB, a big learning step and a reorder for every mistake.

## Sensor powered from a GPIO only while sampling (2026-09-24)

Less time powered in wet soil means less corrosion and self-heating. This depends on the sensor's current, which isn't measured yet.

Other option: always on from the 3V3 pin, simpler but harder on the sensor.

## Epoxy on the electronics, nail polish on the probe edges (2026-09-24)

Published projects report heat-shrink pulling away from the board after about a year, while epoxy lasts. The cut PCB edges absorb water, so they get nail polish.

Other option: heat-shrink alone, quicker to apply.

## JST-XH plug-in connectors (2026-10-02)

The board gets one row of keyed sockets. A worn sensor swaps out without the soldering iron.

Other option: leads soldered to the board, fewer parts but every swap needs desoldering.

## ESP32 in female headers (2026-10-02)

The board can come out for testing or replacement. The headers cost about €1 and add a few mm of height.

Other option: soldered in, slimmer, but replacing it means desoldering 30 pins.

## Home Assistant with MQTT on a Raspberry Pi (2026-10-02)

Home Assistant stores the history, draws a graph per plant and sends phone notifications. The firmware stays my own and publishes readings over MQTT.

Other option: my own server on the Pi, weeks of work for features Home Assistant already has.

## Tailscale for access away from home (2026-10-02)

Tailscale already runs at home, and nothing gets exposed to the internet.

Other option: port forwarding, which would put hand-written code on the open internet.
