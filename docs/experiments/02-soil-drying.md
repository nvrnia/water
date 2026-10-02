# experiment 2: drying curve

**dates:** 2026-09-13 to 2026-09-19

**question:** how fast does a pot dry, and what does the curve look like?

**setup:** sensor A pushed to the line in a 4-inch pot, deliberately overwatered first. 30-minute samples, 64-sample average. Data: [`data/raw/2026-09-13_plant-a_drying.csv`](../../data/raw/2026-09-13_plant-a_drying.csv)

**result:**

| period | change per day |
|---|---|
| 13 → 14 Sep | +55 |
| 14 → 15 Sep | +49 |
| 15 → 16 Sep | +48 |
| 16 → 17 Sep | +39 |
| 17 → 19 Sep | +24 |

1289 → 1535 counts in 6 days. On the air/overwatered scale (3279 / 1199) that's 16% of the way to dry.

**conclusions:**

- drying slows as the soil dries, so the curve can't be extrapolated in a straight line
- the curve stitched cleanly across every restart: NTP timestamps work, and power cycling doesn't shift the sensor
- the pot dried far slower than I expected. Cause: the saucer held water and the soil wicked it back up
- at this rate a full cycle takes over a month, longer than the 21-day buffer

**limits:** 6 restarts left gaps, including 17 Sep 13:52 to 19 Sep 12:16. One pot, one sensor, one start state (flooded), which isn't how I normally water.
