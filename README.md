⚙️ Engineering Summary

The Jinx LED Engine is a custom embedded lighting system built for a Jinx statue display.
Running on an Arduino Nano Every, it drives 14 GRBW NeoPixel LEDs using two independent real-time animation engines:

🌩️ Cloud Lightning Engine (LEDs 0–11)

A randomized micro-timed lightning simulator running under diffused “clouds.”
Each LED has its own timing schedule, flash probability, and brightness curve.

💗 Core Breathing Engine (LEDs 12–13)

A smooth, cinematic breathing cycle with multiple colour modes (pink, amethyst, white, gem-tones), driven by internal state machines and brightness scaling.

Together, they create a layered, organic lighting effect that feels alive and reactive — engineered specifically for physical art display and visual depth enhancement.

🧱 System Architecture
🌩️ Lightning Engine (0–11)

Independent per-LED timers

70% ambient glow baseline

Random lightning bursts (white or tonal variants)

Multi-intensity flashes

Non-synchronized for realism

💗 Breathing Engine (12–13)

Smooth fade-in → hold → fade-out

Mode-based colour selection

Supports saturated gem tones (emerald, sapphire, teal, gold…)

Optional half-brightness cycles

🛠️ Technology Stack
Hardware

⚡ Arduino Nano Every (ATmega4809)

💡 14× GRBW SK6812 NeoPixels

🔌 5V regulated LED rail

Software

🧩 PlatformIO (Arduino framework)

🎨 Adafruit NeoPixel (GRBW)

⏱️ Non-blocking timing loops using millis()

🎛️ Deterministic state machines

Tools

🖥️ Visual Studio Code

🔧 PlatformIO

🔐 GitHub (SSH onboarding)

📁 Project Structure
jinx-led-engine/
 ├── src/
 │   └── main.cpp
 ├── include/
 ├── images/            ← GIFs, photos, render shots
 ├── platformio.ini
 └── README.md

🖼️ Gallery
![Front view](images/jinx_front.jpg)
![Cloud lightning detail](images/jinx_clouds.jpg)
![Internal electronics](images/jinx_wiring.jpg)
