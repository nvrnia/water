# Is the sensor output safe for an ESP32 pin?

Experiment 0, 2026-09-12?

Sources disagreed. Some listed 0 to 3 V out on a 3.3 V supply. Others said the board only works on 5 V and can output up to 5 V. More than about 3.3 V on a GPIO can damage the chip.

Prediction: About 0 V in air and a higher value in water. The two sensors won't read the same, because no two units are identical. For the pot after watering, I predicted 1.5 to 2.0 V, because wet soil is a mix of grains, air and water.

Setup: Sensor powered from the ESP32's 3V3 pin, which measured 3.4 V. AOUT not connected to the ESP32. Multimeter on 20 V DC between AOUT and GND. Probe in air, then in water up to the line, then in air again. Then sensor A in a pot, bone dry and after overwatering.

Result:

| | Sensor A | Sensor B |
|---|---|---|
| Air | 2.70 V | 2.70 V |
| Water | 1.00 V | 1.00 V |
| Air again | Not recorded | 2.70 V |

| Sensor A in the pot | |
|---|---|
| Bone dry, 3 to 4 weeks unwatered | 2.66 V |
| Just overwatered | 1.09 V |

Conclusion: The highest output was 2.70 V, below 3.3 V, so the sensor connects to the ESP32 without a divider. The 5 V half of the test wasn't needed.

My prediction was wrong. Wetter soil reads lower. The overwatered pot read 1.09 V, close to pure water, so the soil prediction didn't hold either. Overwatering filled the pores.

Bone-dry soil sat within 2% of air, so air works as the dry anchor. Real soil covered about 92% of the air-to-water range, from (2.66 − 1.09) / (2.70 − 1.00).

Sensors A and B matched to the meter's resolution of 0.01 V, which only rules out a large difference. I only recorded the return to air for sensor B.
