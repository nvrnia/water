# Data

ADC values are 12-bit counts (0 to 4095) from GPIO 32. Each value is the average of 64 samples. Higher means drier.

| File | What |
|---|---|
| `calibration.csv` | Anchor points per sensor, ADC and multimeter |
| `raw/2026-09-13_plant-a_drying.csv` | Plant A drying after deliberate overwatering, 13 to 19 Sep |
| `raw/2026-10-02_plant-a_INVALID-half-depth.csv` | Probe only half in the soil, kept as evidence, not usable as moisture data |

## Drying run, 13 to 19 Sep

- 30-minute samples, probe at the line, 4-inch pot
- `run` goes up by one at each restart, 6 restarts in this window
- gaps between runs are readings lost from RAM before they were copied out
- saucer held water the whole time, which kept the soil wet from below

## Half-depth file

The probe went back in at half depth after an air reading on 24 Sep. Half the sensing area was in air, so the readings sit near the air value of 3279. Soil and air don't combine linearly in the reading, so the real soil value can't be recovered.
