✨ Animated Showcase

(Recommended: ~1200px wide GIF)

⚙️ Engineering Summary

The Jinx LED Engine is a custom embedded lighting system built for a Jinx statue display.
It runs on an Arduino Nano Every and drives 14 GRBW NeoPixel LEDs using two independent real-time animation engines:

🌩️ Cloud Lightning Engine (LEDs 0–11)

A randomized micro-timed lightning simulator running under diffused “clouds.”
Each LED maintains its own timer, flash probability, and brightness profile, creating a natural, storm-like effect with no global synchronization.

💗 Core Breathing Engine (LEDs 12–13)

A cinematic breathing system for the central “energy core.”
It uses mode-based colour selection (pink, black-amethyst, white, gem-tones) and a smooth fade curve, with brightness scaling per cycle.

Both engines use non-blocking millis()-based scheduling, allowing smooth, deterministic animations without timing interference.
The result is a multi-layered, physically integrated lighting effect engineered for visual depth, contrast, and motion.

🧱 System Architecture
1. Cloud Lightning Engine (0–11)

Independent per-LED timers

~70% ambient glow baseline

Random lightning bursts (white and coloured variants)

Variable flash intensity and interval per LED

Designed to sit under translucent acrylic/cloud diffusion

Goal: create atmospheric motion and subtle chaos under the statue.

2. Core Breathing Engine (12–13)

Smooth fade-in → hold → fade-out breathing curve

Mode-driven colour states:

Pink core

Black-amethyst

True white

Gem-tone random (emerald, sapphire, teal, gold, etc.)

Per-cycle brightness scaling (half or full intensity)

Mode changes only at blackout for clean visual transitions

Goal: provide a controlled, rhythmic “energy core” that defines the overall mood.

🛠️ Technology Stack
Hardware

⚡ Arduino Nano Every (ATmega4809)

💡 14× GRBW SK6812 NeoPixel LEDs

🔌 5 V regulated LED rail

Internal wiring and placement optimized for diffusion and heat considerations

Software

🧩 PlatformIO (Arduino framework)

🎨 Adafruit NeoPixel library (GRBW)

⏱️ Non-blocking timing using millis()

🎛️ State-machine based mode handling

Per-LED animation scheduling for the cloud subsystem

Tooling

🖥️ Visual Studio Code

🔧 PlatformIO extension

🔐 GitHub with SSH workflow

📁 Project Structure
jinx-led-engine/
 ├── src/
 │   └── main.cpp
 ├── include/
 ├── images/            ← GIFs & photos live here
 ├── platformio.ini
 └── README.md

🖼️ Gallery

Add still photos of the statue, cloud details, and internals here:
