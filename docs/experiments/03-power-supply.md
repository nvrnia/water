# experiment 3: laptop USB vs phone charger

**date:** 2026-09-12?

**question:** does swapping the power source change the reading?

**why:** the node will run on a charger, but calibration happened on the laptop. The board's regulator should hide the difference; chargers can be noisier.

**setup:** same sensor, soil and depth. Read AOUT on the laptop, swapped to a phone charger, read again.

**result:** 1.07 V on both (multimeter).

**conclusion:** no difference the meter can see. Calibration done on the laptop holds on a charger.

**limits:** measured with the meter at 10 mV resolution, not the ADC at 0.8 mV. Repeat with ADC readings if it ever matters.
