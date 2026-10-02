# open questions

| question | why it matters | how to find out |
|---|---|---|
| sensor supply current | decides GPIO power vs a transistor | multimeter in series, mA range |
| settling time after power-on | firmware must wait this long before sampling | power from a GPIO, watch the reading |
| what coating does to the readings | anchors may shift | air and water before and after coating |
| why the node restarts | lost data every time | reset reason at boot |
| sensor B through the ADC | B's anchors are unknown | air and water readings |
| is the ADC really nonlinear vs the meter? | low end read ~8% under the meter, high end ~2%, but the high-end readings were days apart | meter and ADC at the same moment, at both ends |
| real watering threshold | 2239 is a guess | note the reading each time the finger says water |
| long-term drift | a drifted sensor looks normal | weekly air and water reference readings |
| deep pots | probe only reaches the top | not solved yet |
