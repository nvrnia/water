# hardware

## node v1 (proposed)

![schematic](schematic-v1-proposed.svg)

| from | to | why |
|---|---|---|
| USB charger | DevKit micro-USB | on-board regulator makes 3.3 V; nothing soldered touches mains |
| GPIO 18* | J1 pin 1 (sensor A VCC) | sensor powered only while sampling, less corrosion |
| GPIO 32 | J1 pin 2 (sensor A AOUT) | ADC1, unaffected by Wi-Fi |
| GND | J1 pin 3 | return |
| GPIO 19* | J2 pin 1 (sensor B VCC) | same as A |
| GPIO 33 | J2 pin 2 (sensor B AOUT) | ADC1 |
| GND | J2 pin 3 | return |
| GPIO 34, 35 | J3, J4 | reserved, not fitted |

\* depends on measuring the sensor's supply current. If it's too high for a GPIO pin, each channel gets a transistor switch and this drawing changes.

Not fitted: a 100 nF capacitor on each ADC input. Averaging already brings noise down to 4 counts.

The KiCad project goes in `kicad/` once it's drawn.
