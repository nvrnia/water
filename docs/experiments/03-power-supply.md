# Does the power source change the reading?

Experiment 3, 2026-09-12?

Calibration happens on the laptop, but the node will run on a phone charger.

Prediction: None written down. The board's regulator should hide the difference, but chargers can be noisier.

Setup: Same sensor, soil and depth. AOUT read with the multimeter on laptop USB, then on a phone charger.

Result: 1.07 V on both.

Conclusion: The multimeter shows no difference, so calibration done on the laptop holds on the charger. The multimeter resolves 10 mV and the ADC about 0.8 mV, so a smaller difference could still exist.
