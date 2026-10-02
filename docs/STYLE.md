# Writing style

How the docs, commits and comments in this repo are written. Example content below is made up. Only the shape matters.

## The voice

Short, plain sentences from the person who built the thing and is writing down what happened. The decision comes first, then the reason. Point at the exact thing: the pin, the file, the reading, the line number. Say what you saw and what you think it means, and keep the two apart. When something went wrong, say it once and move on to what changed.

## Rules

### Sentences

- One idea per sentence. Most sentences stay under 20 words.
- Start with the subject or the action ("The sensor reads...", "I moved..."), never with "So," "Basically," or "Overall,".
- Decision, then reason: "I moved the sensors to ADC1 because ADC2 can't be read while Wi-Fi is on."
- Correct yourself in one line and keep going: "Update: the font was fine. The mock-up was the problem."
- "I" in the logbook, decision log and write-ups. The README is neutral: it describes the system, and setup steps are plain commands ("Flash the board").
- At most one hedge per claim ("I think", "probably"). Stack none.
- Verdicts can be blunt: "This didn't work." "The first enclosure was too small."

### Words

- American spelling: color, analyze, behavior.
- Plain verbs: use, check, measure, change, fix.
- Call a thing the same name every time. If it's "sensor 2" once, it's "sensor 2" everywhere.
- No slang or filler (tbh, like, just, basically, kind of). No caps for emphasis. If something matters, say why it matters.
- Contractions are fine.

### Headings

- Sentence case: "Wiring the sensors". *(default, change if you prefer)*
- The heading says what's in the section. No clever titles, no emoji.
- Logbook entries are headed by date, `## 2026-10-02`, so they sort.

### Lists

- Lists for steps, parts and pins. Prose for reasons.
- Bullets start with the content. No bold label in front.
- Numbered only when the order matters.
- Fragments get no period, sentences do. One or the other per list.

### Numbers and units

- Number, space, unit: 3.3 V, 10 kΩ, 15 min. Percent is attached: 40%. *(SI default, your messages didn't show this)*
- Digits for every measurement, with the raw value next to the converted one: "ADC 1830 (about 41%)".
- Say how it was measured when it matters: "multimeter, at the sensor pins".
- Keep the noise. If it jumped between 1790 and 1850, write that range.

## Templates

**README section**
```
## <What this part is>
<One or two sentences on what it does.>
<Steps to use it, numbered if there are steps.>
<What it doesn't do yet.>
```

**Logbook entry**
```
## 2026-10-02
<What I worked on.>
<What happened, with numbers.>
Next: <one concrete step>
```

**Decision log entry**
```
## <Decision, as a statement> (2026-10-02)
<Why, in two or three sentences.>
Other option: <what I didn't pick, and the reason in one line>
```

**Experiment write-up**
```
## <The question> (e.g. Does sensor depth change the dry reading?)
Prediction: <what I expected and why, written before the test>
Setup: <hardware, where, how long, how it was measured>
Result: <numbers, a table or a plot>
Conclusion: <the answer in one or two sentences, and whether the prediction held>
```

**Problem write-up**
```
## <The symptom, in plain words>
What happened: <what I saw, with numbers>
Cause: <the cause, or "unknown so far" and what's been ruled out>
Fix: <what I changed>
Check: <how I know it's fixed>
```

**Commit message.** Past tense, capital first letter, no period, about 50 characters max. Add a body only when the reason isn't obvious.
```
Added moisture calibration for sensor 2

Dry and wet points were measured again in the new pot.
```

**Code comment.** Say why, or give the unit. Don't repeat what the code says.
```python
# ADC2 can't be read while Wi-Fi is on, so every sensor is on an ADC1 pin
SENSOR_PINS = [32, 33, 34]
READ_INTERVAL_S = 600
```

## Mistakes, wrong predictions and uncertainty

- Say it once, plainly: "My prediction was wrong." Then what happened, then what changed.
- A wrong prediction stays in the write-up as it was written. The conclusion says it didn't hold.
- No drama (disaster, nightmare, finally) and no spin ("a valuable learning experience").
- Claim what was tested, nothing more. "Ran for 3 days on one plant", never "reliable".
- For uncertainty, say what you don't know and what would settle it: "I think the ground is floating. Next is measuring between ESP32 GND and sensor GND."
- A dry line now and then is fine in the logbook. Keep the README, conclusions and commits straight.

## AI tells to avoid

| Avoid | Write instead |
|---|---|
| Em-dash asides ("the sensor, which was new, failed" written with dashes) | Commas, or two sentences |
| "Not X, but Y", "It's not just X, it's Y" | Say Y. Mention X only if a reader would assume it |
| A colon before a reveal ("The culprit: a loose wire.") | "A loose wire caused it." |
| Three adjectives in a row ("simple, robust and scalable") | One accurate word, or a number |
| delve, leverage, seamless | look at, use, smooth (or cut) |
| robust, crucial, comprehensive | reliable with the evidence, important (or cut), full (or cut) |
| "It's worth noting", "In summary", "Overall" | Cut them and state the point |
| A rhetorical question as a transition ("So why did it fail?") | State the cause |
| Announcing ("This section explains...", "Let's look at...") | Start with the content |
| An upbeat ending ("Exciting things ahead!") | End on the last fact or the next step |
| A bold label on every bullet | Plain bullets, or a table if items have names and values |
| Stacked hedges ("may potentially help to some extent") | One hedge or none: "probably helps" |
| A forced "on the one hand / on the other" | Say what you picked and why. The other option gets one line if it matters |
| Additionally, furthermore, moreover, ensure, aims to, journey | Also (or nothing), make sure, does, cut |

## Before and after

### 1. The floating-ground section

Before:

> **seen:** AOUT read a steady 1.97 V and didn't change when the sensor went into water.
>
> **checked, in order:**
>
> | test | expected | got | meaning |
> |---|---|---|---|
> | 3V3 pin to GND | ~3.3 V | 3.4 V | meter and board fine |
> | sensor VCC to GND | ~3.3 V | 3.4 V | VCC wire connected |
> | sensor GND to ESP32 GND | 0.00 V | 2.45 V | **ground not connected** |
>
> **cause:** the sensor's ground wire wasn't joined to the ESP32's ground on the breadboard. With no return path the sensor wasn't running, and AOUT was floating.
>
> **fix:** sensor plugged straight onto the ESP32's pins, no breadboard. Ground check read 0.00 V, then air 2.70 V and water 1.00 V.
>
> **lesson:** test something whose right answer you know for sure. Two points that should be connected must read 0 V.

After:

> ## AOUT read 1.97 V in air and in water
>
> What happened: The sensor output read a steady 1.97 V. It didn't change when the probe went into water.
>
> Cause: The sensor's ground wire wasn't joined to the ESP32's ground on the breadboard. With no return path the sensor wasn't running, and AOUT was floating. I found it by measuring points with a known answer, in this order:
>
> | Test | Expected | Got | Meaning |
> |---|---|---|---|
> | 3V3 pin to GND | About 3.3 V | 3.4 V | Meter and board fine |
> | Sensor VCC to GND | About 3.3 V | 3.4 V | VCC wire connected |
> | Sensor GND to ESP32 GND | 0.00 V | 2.45 V | Ground not connected |
>
> Fix: I plugged the sensor straight onto the ESP32's pins, without the breadboard.
>
> Check: Sensor GND to ESP32 GND read 0.00 V. AOUT then read 2.70 V in air and 1.00 V in water.

What changed: the symptom became the heading, the bold labels became the template fields, "lesson" was cut, and the fix and the check got their own lines.

### 2. A generic AI paragraph

Before:

> Choosing the right sensor was a crucial step in this journey. Rather than relying on traditional resistive probes, I leveraged capacitive sensors — a robust, reliable and cost-effective solution. But why does this matter? Resistive sensors corrode over time. In summary, this decision ensures seamless long-term monitoring.

After:

> I used capacitive sensors instead of resistive ones. Resistive probes pass a current through the soil, and the metal corrodes after a few weeks. These sensors have to stay in the pots for months.