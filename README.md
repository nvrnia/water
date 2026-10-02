# water

Soil moisture monitoring for my houseplants. Each plant gets a capacitive sensor, an ESP32 reads it, and the readings end up on my phone.

This is a first-year EEE learning project. Every design decision in here came from a measurement or a calculation, and the notes show which. Failed attempts are kept too.

![node v1 schematic, proposed](hardware/schematic-v1-proposed.svg)

## status

| part | state |
|---|---|
| sensor characterisation | done for sensor A, B partly |
| breadboard node, one sensor | running, logs every 30 min, serves CSV over Wi-Fi |
| permanent node v1 (perfboard, two sensors) | designed, not built |
| Home Assistant on a Raspberry Pi | chosen, not set up |
| enclosure | not started |

## how it works

```
soil water → capacitance → sensor (TL555I) → 1.0–2.7 V → ESP32 ADC1, 12-bit
          → 64-sample average → Wi-Fi → (planned) MQTT → Home Assistant → phone
```

Wet soil has a higher dielectric constant than dry soil (water is about 80, dry soil 2–5), so the sensor's capacitance rises with moisture. On these boards the output voltage **drops** as the soil gets wetter.

## measured so far

| what | result |
|---|---|
| sensor output, air / water | 2.70 V / 1.00 V (multimeter) |
| bone-dry soil / overwatered soil | 2.66 V / 1.09 V, so real soil covers ~92% of the air-water range |
| ADC noise, single sample | ~74 counts spread |
| ADC noise, 64-sample average | ~4 counts spread |
| sensor-to-sensor, air and water | A and B within 0.01 V on the meter |
| laptop USB vs phone charger | no difference on the meter |
| window open vs closed | 3–5 counts, inside the noise |
| drying rate after overwatering | 55 → 24 counts per day over 6 days, slowing down |

Details and raw numbers are in [`docs/experiments/`](docs/experiments/) and [`data/`](data/).

## repo

| folder | contents |
|---|---|
| [`docs/`](docs/) | logbook, decisions with reasons, experiments, problems, open questions |
| [`firmware/`](firmware/) | the running sketch, plus the stages it was built in |
| [`hardware/`](hardware/) | schematic, parts list |
| [`data/`](data/) | raw readings and calibration points |

## hardware

ESP32 WROOM-32 DevKit V1 · capacitive soil moisture sensor with TL555I and 662K regulator · perfboard (planned) · USB power. Parts and prices in [`hardware/bom.md`](hardware/bom.md).
