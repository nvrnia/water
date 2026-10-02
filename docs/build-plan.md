# Build plan, node v1

Each step ends with a check that says it's done.

| Step | What | Done when |
|---|---|---|
| P1 | Seal both sensors (nail polish on the edges, epoxy on the electronics) and measure the anchors again | New anchors for A and B, change in range written down |
| P2 | Soldering iron, practice on scrap board | Every practice joint passes continuity |
| P3 | Measure sensor current and settling time from a GPIO | Both are measured numbers |
| P4 | Schematic in KiCad, pin current limit from the ESP32 datasheet, perfboard layout on paper | Electrical rules check passes |
| P5 | Solder node v1 | Readings match the breadboard within 4 counts |
| P6 | Firmware v2: two sensors, switched power, reset reason, range check, MQTT | A week without unexplained restarts |
| P7 | Printed enclosure and depth collar | Pulling a lead doesn't load a solder joint |
| P8 | Raspberry Pi, MQTT broker, Home Assistant, a graph per plant, notifications | Unplugging a node only loses the minutes it was off |
| P9 | Long run with weekly reference readings and a finger-check log | Three months of drift data per sensor |
