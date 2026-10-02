# How fast does the pot dry after overwatering?

Experiment 2, 13 to 19 Sep 2026

Prediction: None written down before the run.

Setup: Sensor A pushed in to the line in a 4-inch pot, overwatered on purpose first. One reading every 30 min, each the average of 64 samples. Data: [`data/raw/2026-09-13_plant-a_drying.csv`](../../data/raw/2026-09-13_plant-a_drying.csv)

Result:

| Period | Change per day |
|---|---|
| 13 to 14 Sep | +55 |
| 14 to 15 Sep | +49 |
| 15 to 16 Sep | +48 |
| 16 to 17 Sep | +39 |
| 17 to 19 Sep | +24 |

The reading went from 1289 to 1535 in 6 days. On the anchor scale (air 3279, overwatered 1199) that's 16% dry.

Conclusion: Drying slows down as the soil dries, so the curve can't be extended with a straight line.

The curve lined up across every restart. The NTP timestamps work, and a power cycle doesn't shift the sensor.

The pot dried far slower than my 3 to 4 day watering habit suggested, because the saucer held water. At this rate a full cycle takes over a month, longer than the 21-day buffer.

Six restarts left gaps, the longest from 17 Sep 13:52 to 19 Sep 12:16. This is one pot, one sensor and a flooded start, which isn't how I normally water.
