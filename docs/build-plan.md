# build plan, node v1

Each step ends with a check that says it's done.

| step | what | done when |
|---|---|---|
| P1 | seal both sensors (nail polish on edges, epoxy on the electronics), re-measure anchors | new anchors for A and B, change in range written down |
| P2 | soldering iron, practice on scrap board | every practice joint passes continuity |
| P3 | measure sensor current and settling time from a GPIO | both are measured numbers |
| P4 | schematic in KiCad, check pin current limit in the ESP32 datasheet, perfboard layout on paper | electrical rules check passes |
| P5 | solder node v1 | readings match the breadboard within 4 counts |
| P6 | firmware v2: two sensors, switched power, reset reason, range check, MQTT | a week without unexplained restarts |
| P7 | printed enclosure and depth collar | pulling a lead doesn't load a solder joint |
| P8 | Raspberry Pi, MQTT broker, Home Assistant, per-plant graphs, notifications | unplugging a node only loses the minutes it was off |
| P9 | long run: weekly reference readings, finger-check log | three months of drift data per sensor |
