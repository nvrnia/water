# decisions

| # | decision | alternatives | why | based on |
|---|---|---|---|---|
| 1 | one Wi-Fi node per plant cluster, up to 4 sensors each | one central controller with long cables | short analog wires pick up less noise; adding a plant means adding a node; no cables across the room | requirements |
| 2 | capacitive sensors | resistive | resistive probes pass current through wet soil, which corrodes them by electrolysis | physics |
| 3 | ESP32 WROOM DevKit V1 | ESP32-C3, ESP8266, Pico W | 6 ADC1 pins broken out on this board (GPIO 32–36, 39), enough for 4 sensors with Wi-Fi on, and the most beginner material. ESP8266 has one analog input | Espressif docs |
| 4 | ADC1 pins only (GPIO 32–36, 39 on this board) | any analog pin | ADC2 is taken by the Wi-Fi driver | Espressif docs |
| 5 | no external ADC, no amplifier | ADS1115, op-amp | 12-bit gives ~2100 steps across the sensor's 1.7 V swing; soil varies more than that | calculation |
| 6 | no voltage divider | divider on AOUT | measured max output 2.70 V, under the ESP32's 3.3 V | experiment 0 |
| 7 | TL555I sensor with regulator | ME555 version | ME555 board only works on 5 V | retailer specs |
| 8 | own firmware in C++, built in stages | ESPHome | learning to program was a goal; stages keep one unknown at a time | my choice |
| 9 | 64-sample average | single samples, 100 nF capacitor | cut noise from 74 to 4 counts with no parts | experiment 1 |
| 10 | no temperature compensation | add a temperature sensor | window open vs closed moved 3–5 counts, inside the noise | experiment 4 |
| 11 | per-sensor calibration, air and water as anchors | one calibration for all | sensors and ADCs vary; real soil reaches ~92% of the air-water range anyway | experiments 0, 2 |
| 12 | 30 min sampling | 1 s, 1 h | soil changes over days, watering over minutes. 30 min catches both | sampling reasoning |
| 13 | alert at 2239, re-arm at 1800 | single threshold | midpoint of the anchors as a first guess; two thresholds stop repeated alerts from noise. To be tuned against finger checks | my choice |
| 14 | probe pushed to the line | shallow | in a 4-inch pot it covers most of the soil | my choice |
| 15 | perfboard, hand-soldered | custom PCB | cheap, fast, fine for a first build | my choice |
| 16 | sensor powered from a GPIO only while sampling | always on from 3V3 | less corrosion and self-heating. Pending a current measurement | published reports |
| 17 | JST-XH plug-in sensors | soldered leads | tidier, and a worn sensor swaps without the iron | my choice |
| 18 | ESP32 in female headers | soldered in | can come out for testing or replacement; ~€1 | my choice |
| 19 | Home Assistant + MQTT on a Raspberry Pi | own server, cloud service | stores history, draws per-plant graphs, phone notifications; no app to build | my choice |
| 20 | epoxy on the electronics, nail polish on the probe edges | heat-shrink only | heat-shrink is reported to peel after about a year | published projects |

## rejected and why

- **central controller with long cables:** poor expandability, noise on long analog lines, cables across the room
- **ESP32-C6:** one ADC unit, fewer channels, less beginner material
- **cloud service (ThingSpeak etc.):** data on someone else's server, free tiers change
- **port forwarding to reach the node from outside:** exposes hand-written code to the internet. Tailscale instead
