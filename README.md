# Jinx LED Engine  
![Build](https://img.shields.io/badge/build-passing-brightgreen?style=for-the-badge)  
![PlatformIO](https://img.shields.io/badge/PlatformIO-arduino-orange?style=for-the-badge&logo=platformio)  
![C++](https://img.shields.io/badge/C%2B%2B-embedded-blue?style=for-the-badge&logo=c%2B%2B)  
![NeoPixel](https://img.shields.io/badge/LED-GRBW%20NeoPixel-6f42c1?style=for-the-badge)  
![License](https://img.shields.io/badge/license-MIT-lightgrey?style=for-the-badge)


---

## ✨ Animated Showcase
*(Recommended: ~1200px wide GIF)*

![Jinx LED Engine](images/jinx_led_engine.gif)


---

## ⚙️ Engineering Summary

The **Jinx LED Engine** is a custom embedded lighting system built for a Jinx statue display.  
It runs on an **Arduino Nano Every** and drives **14 GRBW NeoPixel LEDs** using two independent real-time animation engines.


---

## 🌩️ Cloud Lightning Engine (LEDs 0–11)

A randomized micro-timed lightning simulator running under diffused “clouds.”  
Each LED maintains its own timer, flash probability, and brightness profile, producing a storm-like effect with no synchronization.


---

## 💗 Core Breathing Engine (LEDs 12–13)

A cinematic breathing system for the statue’s “energy core.”  
Uses mode-based color selection (pink, black-amethyst, white, gem-tones) and smooth fade curves.


---

## 🧱 System Architecture

### 1. Cloud Lightning Engine (0–11)

- Independent per-LED timers  
- ~70% ambient baseline  
- Random lightning bursts  
- Variable intensity & interval  
- Designed for acrylic/cloud diffusion  

**Goal:** natural atmospheric motion and subtle chaos.


### 2. Core Breathing Engine (12–13)

- Fade-in → hold → fade-out curve  
- Modes: Pink / Amethyst / White / Gem-tone random  
- Per-cycle brightness scaling  
- Mode switching only at blackout  

**Goal:** rhythmic “energy core” defining the statue’s mood.


---

## 🛠️ Technology Stack

### Hardware
- Arduino Nano Every  
- 14× GRBW SK6812 NeoPixel LEDs  
- 5 V regulated rail  

### Software
- PlatformIO (Arduino framework)  
- Adafruit NeoPixel library  
- Non-blocking timing  
- Mode/state engine  

### Tools
- VS Code  
- PlatformIO extension  
- GitHub SSH workflow  


---

## 📁 Project Structure

