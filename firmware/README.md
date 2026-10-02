# Firmware

Arduino framework (C++), built in the Arduino IDE on Windows.

| Folder | What |
|---|---|
| `node/` | The sketch on the node now |
| `stages/` | The steps it was built in, one new thing per step |

## Build

1. Install the board package "esp32 by Espressif Systems" in the Arduino IDE.
2. Select ESP32 Dev Module, upload speed 115200.
3. In the sketch folder, copy `secrets.example.h` to `secrets.h` and fill in the Wi-Fi details.
4. Upload, open the Serial Monitor at 115200 and press EN to see the boot output.

`secrets.h` is in `.gitignore`. Never commit it.

## Stages

| Stage | Added | What it showed |
|---|---|---|
| 01_hello | Serial output | Compiler, driver, COM port and flashing work |
| 02_adc_raw | `analogRead` on GPIO 32 | Sensor reaches the ADC, raw spread about 74 counts |
| 03_multisample | 64-sample average | Spread down to about 4 counts |
| 04_wifi_connect | Wi-Fi | Board joins the 2.4 GHz network |
| 05_webserver | HTTP | Phone reads the sensor on the local network |
| node | NTP time, 30 min schedule, circular buffer | History with real timestamps |
