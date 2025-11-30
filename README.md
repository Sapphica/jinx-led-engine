# jinx-led-engine  
Cinematic LED engine powering the Jinx Statue lighting project.  
14× GRBW NeoPixels driven by a Nano Every using custom breathing curves, gem-tone sparkle effects, and dynamic mode transitions.

## ✨ Features

- Sparkle engine with 12 independently timed LEDs  
- Cinematic breathing cycle for LEDs 12–13  
- Auto-mode switching: pink, amethyst/white, gem-tone random  
- Per-cycle brightness variation  
- Full C++ class-based architecture (no `.ino` spaghetti)  
- Designed for PlatformIO + VS Code  

## 📁 Project Structure

src/
├── main.cpp → Arduino entry
├── led_engine.cpp → LED logic implementation
└── led_engine.h → Engine interface & state

## 🚀 Build & Upload

1. Install VS Code  
2. Install PlatformIO extension  
3. Open the folder `jinx-led-engine/`  
4. Click **Build** → **Upload**

## 🧩 Hardware

- **Arduino Nano Every**  
- **14× GRBW NeoPixels** (Adafruit / compatible)  
- Powered from regulated 5V rail

## 📜 License

MIT — free to use in your own builds.
