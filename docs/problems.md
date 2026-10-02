# problems

## floating ground

**seen:** AOUT read a steady 1.97 V and didn't change when the sensor went into water.

**checked, in order:**

| test | expected | got | meaning |
|---|---|---|---|
| 3V3 pin to GND | ~3.3 V | 3.4 V | meter and board fine |
| sensor VCC to GND | ~3.3 V | 3.4 V | VCC wire connected |
| sensor GND to ESP32 GND | 0.00 V | 2.45 V | **ground not connected** |

**cause:** the sensor's ground wire wasn't joined to the ESP32's ground on the breadboard. With no return path the sensor wasn't running, and AOUT was floating.

**fix:** sensor plugged straight onto the ESP32's pins, no breadboard. Ground check read 0.00 V, then air 2.70 V and water 1.00 V.

**lesson:** test something whose right answer you know for sure. Two points that should be connected must read 0 V.

## Wi-Fi hang with no output

**seen:** dots forever, never an IP.

**cause:** password left empty in the sketch. The board can't tell a wrong password from any other connection failure.

**fix:** password in. The sketch now gives up after 20 s and prints the status code instead of hanging, and credentials live in `secrets.h`.

## stale IP address

**seen:** browser timed out; ping said "destination host unreachable".

**cause:** the board was running an older sketch, and the IP I typed was from a previous boot.

**fix:** read the current IP from Serial after pressing EN. Still to do: a fixed DHCP lease on the router.

## restarts wipe the history

**seen:** 6 restarts between 13 and 19 Sep, one more on 2 Oct. Each restart empties the RAM buffer.

**cause:** unknown. Could be power dips, router restarts, or a crash.

**next:** log `esp_reset_reason()` at boot and show it on the web page, since no laptop is watching Serial. Long term, Home Assistant stores readings as they arrive, so a restart only loses minutes.

## half-depth probe

**seen:** reading jumped to ~3170, close to air (3279). The drying trend predicted ~1800 at most.

**cause:** the probe went back in only halfway after being pulled out for an air reading. Half the sensing area was measuring air.

**fix:** pushed back to the line, soil pressed around it. Planned: a printed collar that fixes the depth, and a firmware check that flags readings above bone-dry soil as "sensor out of soil?".

**lesson:** a placement error looked like a believable dry plant. Nothing flagged it.

## slow drying

**seen:** 6 days after overwatering, the pot had only dried 16% of the way.

**cause:** the saucer under the pot held water, and the soil wicked it back up.

**fix:** empty the saucer 15–30 min after watering.
