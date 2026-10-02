# Problems

## AOUT read 1.97 V in air and in water

What happened: The sensor output read a steady 1.97 V. It didn't change when the probe went into water.

Cause: The sensor's ground wire wasn't joined to the ESP32's ground on the breadboard. With no return path the sensor wasn't running, and AOUT was floating. I found it by measuring points with a known answer, in this order:

| Test | Expected | Got | Meaning |
|---|---|---|---|
| 3V3 pin to GND | About 3.3 V | 3.4 V | Meter and board fine |
| Sensor VCC to GND | About 3.3 V | 3.4 V | VCC wire connected |
| Sensor GND to ESP32 GND | 0.00 V | 2.45 V | Ground not connected |

Fix: I plugged the sensor straight onto the ESP32's pins, without the breadboard.

Check: Sensor GND to ESP32 GND read 0.00 V. AOUT then read 2.70 V in air and 1.00 V in water.

## Wi-Fi never connected and gave no error

What happened: The Serial Monitor printed dots forever and never an IP address.

Cause: The password in the sketch was empty. The board can't tell a wrong password from any other connection failure.

Fix: I added the password. The sketch now gives up after 20 s and prints the status code. Credentials live in `secrets.h`.

Check: The board printed its IP address after a short row of dots.

## Browser timed out on the node's address

What happened: The phone's browser timed out. Ping from the PC returned "destination host unreachable".

Cause: The board was running an older sketch, and the address I typed came from an earlier boot.

Fix: I read the current address from the Serial Monitor after pressing EN. A fixed DHCP lease on the router is still to do.

Check: The page loaded on the phone and showed a reading of 1199.

## Restarts wipe the history

What happened: The node restarted 6 times between 13 and 19 Sep and once on 2 Oct. Each restart empties the RAM buffer.

Cause: Unknown so far. Power dips, router restarts and crashes are all possible, and none is ruled out.

Fix: Not fixed yet. Firmware v2 will record the reset reason at boot and show it on the web page, because no laptop watches Serial. Home Assistant will store readings as they arrive, so a restart only loses minutes.

Check: A week with no restarts, or every restart explained by its logged reason.

## Reading jumped to near the air value

What happened: On 2 Oct the reading sat around 3170, close to air (3279). The drying trend pointed to about 1800 at most.

Cause: The probe went back in at half depth after the air reading on 24 Sep. Half the sensing area was in air.

Fix: I pushed the probe to the line and pressed the soil around it. Planned: a printed collar that sets the depth, and a firmware check that flags any reading above bone-dry soil.

Check: Pending. The readings after reseating should drop well below 3170.

## Pot dried much slower than expected

What happened: 6 days after overwatering, the pot was only 16% dry (1289 to 1535).

Cause: The saucer under the pot held water, and the soil soaked it back up.

Fix: I empty the saucer 15 to 30 min after watering.

Check: Not tested yet. The next drying run should be faster.
