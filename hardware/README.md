# Hardware

## Node v1 (proposed)

![Schematic](schematic-v1-proposed.svg)

| From | To | Why |
|---|---|---|
| USB charger | DevKit micro-USB | On-board regulator makes 3.3 V, nothing soldered touches mains |
| GPIO 18* | J1 pin 1, sensor A VCC | Sensor powered only while sampling, less corrosion |
| GPIO 32 | J1 pin 2, sensor A AOUT | ADC1, still readable with Wi-Fi on |
| GND | J1 pin 3 | Return |
| GPIO 19* | J2 pin 1, sensor B VCC | Same as sensor A |
| GPIO 33 | J2 pin 2, sensor B AOUT | ADC1 |
| GND | J2 pin 3 | Return |
| GPIO 34, 35 | J3, J4 | Reserved, not fitted |

\* Depends on the sensor's supply current. If a GPIO pin can't supply it, each channel gets a transistor switch and this drawing changes.

There's no 100 nF capacitor on the ADC inputs. Averaging already brings the noise down to 4 counts.

The KiCad project goes in `kicad/` once it's drawn.
