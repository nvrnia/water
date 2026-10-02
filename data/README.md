# data

All raw ADC values are 12-bit counts (0–4095) from GPIO 32, each the average of 64 samples. **Higher means drier.**

| file | what |
|---|---|
| `calibration.csv` | anchor points per sensor, ADC and multimeter |
| `raw/2026-09-13_plant-a_drying.csv` | plant A drying after deliberate overwatering, 13–19 Sep |
| `raw/2026-10-02_plant-a_INVALID-half-depth.csv` | probe only half in the soil. Kept as evidence, not usable as moisture data |

## 2026-09-13_plant-a_drying.csv

- 30-minute samples, probe pushed in to the line, 4-inch pot
- `run` counts boots: the node restarted 6 times in this window and lost its RAM buffer each time. Gaps between runs are readings that were never copied out
- the saucer held water the whole time, which kept the soil wet from below

## the invalid file

Probe sat at half depth after being pulled out for an air reading on 24 Sep. Half the sensing area was in air, so readings sit near the air value (3279). The soil and air parts don't combine linearly, so the real soil value can't be recovered from these numbers.
