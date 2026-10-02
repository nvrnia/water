# How noisy is the ADC, and does averaging fix it?

Experiment 1, 2026-09-12?

Prediction: The multimeter read 1.09 V on AOUT just before. The ADC should give 1.09 / 3.3 × 4095 ≈ 1353 counts.

Setup: Sensor A in the overwatered pot, AOUT on GPIO 32. First single samples 1 s apart. Then one value per second, each the average of 64 samples taken 2 ms apart.

Result:

| | Readings | Spread |
|---|---|---|
| Single samples | 1292, 1242, 1231, 1218, 1239 | 74 counts, about 60 mV |
| 64-sample average | 11 values from 1229 to 1233 | 4 counts, about 3 mV |

The single samples averaged 1244, which is 1.00 V. That's about 8% below the multimeter.

Conclusion: My prediction of 1353 was about 8% high.

Averaging cut the spread about 18 times. Random noise should drop by √64 = 8 times, and 5 samples are too few to read much into the gap.

Averaging didn't remove the 8% offset, because that error is systematic. The offset doesn't matter here. Calibration maps ADC counts to ADC counts and never converts to volts.

4 counts is about 0.2% of the working range, so I didn't fit the 100 nF capacitor Espressif suggests.
