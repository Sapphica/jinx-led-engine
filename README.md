Jinx LED Engine










✨ Animated Showcase

(Recommended: ~1200px GIF)

⚙️ Engineering Summary

The Jinx LED Engine is a custom embedded lighting system built for a Jinx statue display. It runs on an Arduino Nano Every and drives 14 GRBW NeoPixel LEDs using two independent, real-time animation engines.

🌩️ Cloud Lightning Engine (LEDs 0–11)

A randomized micro-timed lightning simulator running under diffused “clouds.”
Each LED maintains its own timer, flash probability, and brightness profile, creating a natural, storm-like flicker with no global synchronization.

💗 Core Breathing Engine (LEDs 12–13)

A cinematic breathing system for the statue’s central “energy core.”
Uses mode-based colour selection (pink, black-amethyst, white, gem-tones) and a smooth fade curve, with brightness scaling each cycle.

Both engines use non-blocking millis() scheduling, producing deterministic, layered animation without timing interference.

🧱 System Architecture
1. Cloud Lightning Engine

Independent per-LED timers

~70% ambient baseline glow

Random lightning bursts (white + coloured)

Per-LED intensity + interval variation

Optimized to sit under acrylic/cloud diffusion

Goal: atmospheric motion and subtle chaotic flicker.

2. Core Breathing Engine

Smooth fade-in → hold → fade-out curve

Colour modes:

Pink

Black-amethyst

True white

Gem-tone random (emerald, sapphire, teal, gold, etc.)

Per-cycle brightness scaling

Mode changes only during blackout for clean transitions

Goal: a rhythmic, controlled “energy core” that sets the tone.

🛠️ Technology Stack
Hardware

⚡ Arduino Nano Every (ATmega4809)

💡 14× GRBW SK6812 NeoPixel LEDs

🔌 5 V regulated LED rail

Software

🧩 PlatformIO (Arduino framework)

🎨 Adafruit NeoPixel library

⏱️ Non-blocking timing

🎛️ State-machine mode system

Tooling

🖥️ VS Code

🔧 PlatformIO extension

🔐 GitHub SSH workflow

📁 Project Structure
jinx-led-engine/
 ├── src/
 │   └── main.cpp
 ├── include/
 ├── images/
 ├── platformio.ini
 └── README.md

🖼️ Gallery (Optional)

Add photos here:
