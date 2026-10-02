# experiment 1: ADC noise and averaging

**date:** 2026-09-12?

**question:** how noisy is a single ADC reading, and does averaging fix it?

**setup:** sensor A in overwatered soil, AOUT on GPIO 32. The meter had read 1.09 V on AOUT just before.

**prediction:** 1.09 / 3.3 × 4095 ≈ 1353 counts.

**result:**

| | readings | spread |
|---|---|---|
| single samples, 1 s apart | 1292, 1242, 1231, 1218, 1239 | 74 counts ≈ 60 mV |
| 64-sample average, 1 s apart | 11 readings, 1229–1233 | 4 counts ≈ 3 mV |

Mean of the single samples is 1244, which is 1.00 V, about 8% under the meter.

**conclusions:**

- averaging 64 samples cut the spread by ~18×. Random noise should drop by √64 = 8×; the five-sample "before" set is too small to read much into the difference
- averaging fixes random error, not offset. The 8% gap to the meter stayed
- the offset doesn't matter here: calibration maps ADC counts to ADC counts and never converts to volts
- 4 counts is ~0.2% of the working range. The 100 nF input capacitor Espressif suggests wasn't fitted
