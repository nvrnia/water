# experiment 0: sensor output voltage

**date:** 2026-09-12?

**question:** what voltage does the sensor put out, and is it safe for an ESP32 pin?

**why:** sources disagreed. Some said 0–3 V on 3.3 V supply, some said the board only works on 5 V and can output up to 5 V. More than ~3.3 V into a GPIO risks the chip.

**setup:** sensor powered from the ESP32's 3V3 pin (measured 3.4 V). AOUT left unconnected, multimeter on 20 V DC between AOUT and GND. Probe in air, then in water up to the line, then air again.

**prediction (mine, written before measuring):**

- air: about 0 V
- water: higher than air
- the two sensors won't read the same

**result:**

| | sensor A | sensor B |
|---|---|---|
| air | 2.70 V | 2.70 V |
| water | 1.00 V | 1.00 V |
| air again | not recorded | 2.70 V |

Soil, sensor A in the pot:

| | |
|---|---|
| bone dry, 3–4 weeks unwatered | 2.66 V |
| just overwatered | 1.09 V |

I predicted 1.5–2.0 V for the watered soil, reasoning that soil is a mix of grains, air and water. Overwatering filled the pores, so it read close to pure water.

**conclusions:**

- max output 2.70 V, below 3.3 V. No divider needed
- polarity is inverted: wetter reads lower. Firmware has to flip the mapping
- the 5 V half of the test wasn't needed
- bone-dry soil sits within 2% of air, so air works as the dry anchor
- real soil covers ~92% of the air-to-water range: (2.66 − 1.09) / (2.70 − 1.00)
- A and B match to the meter's resolution (0.01 V). That only rules out a big difference

**limits:** one meter, two decimals. Repeatability only recorded for B.
