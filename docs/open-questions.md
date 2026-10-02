# Open questions

| Question | Why it matters | How to find out |
|---|---|---|
| Sensor supply current | Decides between GPIO power and a transistor | Multimeter in series, mA range |
| Settling time after power-on | Firmware has to wait this long before sampling | Power the sensor from a GPIO and watch the reading |
| Effect of coating on the readings | The anchors may shift | Air and water before and after coating |
| Why the node restarts | Every restart loses data | Reset reason at boot |
| Sensor B through the ADC | Sensor B has no ADC anchors yet | Air and water readings |
| Is the ADC nonlinear against the multimeter? | Low end read about 8% under the meter, high end about 2%, but the high-end values were taken days apart | Multimeter and ADC at the same moment, at both ends |
| Real watering threshold | ADC 2239 is a guess | Note the reading each time a finger check says water |
| Long-term drift | A drifted sensor still looks normal | Weekly air and water readings |
| Deep pots | The probe only reaches the top | Not solved yet |
