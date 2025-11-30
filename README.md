# Jinx LED Engine

![Build](https://img.shields.io/badge/build-passing-8A2BE2?style=for-the-badge)
![PlatformIO](https://img.shields.io/badge/PlatformIO-Arduino-9340ff?style=for-the-badge&logo=platformio)
![C++](https://img.shields.io/badge/C%2B%2B-Embedded-purple?style=for-the-badge&logo=c%2B%2B)
![NeoPixel](https://img.shields.io/badge/GRBW-SK6812-DA70D6?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-9370DB?style=for-the-badge)

---

## ✨ Animated Showcase  
*(Place your GIF below — full-width recommended)*

![Showcase](docs/animated_showcase.gif)

---

## ⚙️ Engineering Summary

The **Jinx LED Engine** is a custom embedded lighting controller designed for a Jinx statue display.  
It runs on an **Arduino Nano Every** and drives **14× GRBW SK6812 NeoPixels** using two independent real-time animation engines:

- **Cloud Lightning Engine (LEDs 0–11)**  
  Randomized micro-timed lightning flashes running under diffused acrylic "clouds."

- **Core Breathing Engine (LEDs 12–13)**  
  A cinematic breathing and color-mode core for the statue’s central energy node.

The system uses fully non-blocking scheduling (`millis()`), enabling deterministic timing and multi-layered physical lighting depth.

---

## 🌩️ Cloud Lightning Engine (LEDs 0–11)

- Independent micro-timed LED engines  
- ~70% ambient glow baseline  
- Random lightning bursts  
- Intensity & interval variation per LED  
- Designed for translucent cloud diffusion  
- **Goal:** dynamic "storm under glass" motion

---

## 💗 Core Breathing Engine (LEDs 12–13)

- Fade-in → hold → fade-out breathing cycle  
- Color-mode states: Pink / Amethyst / White / Gem-tones  
- Half or full brightness scaling per cycle  
- Mode changes only at blackout for seamless transitions  
- **Goal:** rhythmic “energy core” pulse

---

## 🧱 System Architecture

### 1. Cloud Lightning Engine
- Lightning probability per LED  
- Brightness shaping  
- Randomized timing windows  

### 2. Core Breathing Engine
- Mode selection logic  
- Per-cycle brightness multiplier  
- Controlled color palette  

### Hardware Stack
- Arduino Nano Every  
- 14× GRBW SK6812 LEDs  
- 5 V regulated rail  

### Software Stack
- PlatformIO  
- Adafruit NeoPixel  
- VS Code  
- Git (SSH)

---

## 🖼️ Gallery

*(Add any photos here — wiring, diffusion panels, the finished statue, etc.)*

![Photo 1](docs/gallery_1.jpg)  
![Photo 2](docs/gallery_2.jpg)  
![Photo 3](docs/gallery_3.jpg)

---
