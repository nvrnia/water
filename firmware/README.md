# firmware

Arduino framework (C++), built in the Arduino IDE on Windows.

| folder | what |
|---|---|
| `node/` | the sketch currently running on the node |
| `stages/` | the steps it was built in, one new thing at a time |

## build

1. Arduino IDE, board package **esp32 by Espressif Systems**
2. board: **ESP32 Dev Module**, upload 115200
3. in the sketch folder, copy `secrets.example.h` to `secrets.h` and put the Wi-Fi details in it
4. upload, open Serial Monitor at 115200, press EN to see boot output

`secrets.h` is in `.gitignore`. Never commit it.

## stages

| stage | added | what it proved |
|---|---|---|
| 01_hello | serial output | compiler, driver, COM port, flashing all work |
| 02_adc_raw | `analogRead` on GPIO 32 | sensor reaches the ADC; raw spread ~74 counts |
| 03_multisample | 64-sample average | spread down to ~4 counts |
| 04_wifi_connect | Wi-Fi | board joins the 2.4 GHz network |
| 05_webserver | HTTP | phone can read the sensor on the local network |
| node | NTP time, 30 min schedule, circular buffer | history with real timestamps |
