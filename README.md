# Jinx LED Engine  
![Build](https://img.shields.io/badge/build-passing-brightgreen?style=for-the-badge)  
![PlatformIO](https://img.shields.io/badge/PlatformIO-arduino-orange?style=for-the-badge&logo=platformio)  
![C++](https://img.shields.io/badge/C%2B%2B-embedded-blue?style=for-the-badge&logo=c%2B%2B)  
![NeoPixel](https://img.shields.io/badge/LED-GRBW%20NeoPixel-6f42c1?style=for-the-badge)  
![License](https://img.shields.io/badge/license-MIT-lightgrey?style=for-the-badge)

<br>
<img src="https://via.placeholder.com/900x1/eeeeee/eeeeee">
<br>

## ✨ Animated Showcase  
*(Recommended: ~1200px wide GIF)*

<br>
<img src="https://via.placeholder.com/900x1/eeeeee/eeeeee">
<br>

## ⚙️ Engineering Summary

The **Jinx LED Engine** is a custom embedded lighting system built for a Jinx statue display.  
It runs on an **Arduino Nano Every** and drives **14 GRBW NeoPixel LEDs** using two independent real-time animation engines.

<br>
<img src="https://via.placeholder.com/900x1/eeeeee/eeeeee">
<br>

## 🌩️ Cloud Lightning Engine (LEDs 0–11)

A randomized micro-timed lightning simulator running under diffused “clouds.”  
Each LED maintains its own timer, flash probability, and brightness profile.

<br>
<img src="https://via.placeholder.com/900x1/eeeeee/eeeeee">
<br>

## 💗 Core Breathing Engine (LEDs 12–13)

A cinematic breathing system for the statue’s “energy core.”  
Uses mode-based color selection and smooth fade curves.

<br>
<img src="https://via.placeholder.com/900x1/eeeeee/eeeeee">
<br>

## 🧱 System Architecture

### 1. Cloud Lightning Engine (0–11)
- Independent per-LED timers  
- ~70% ambient baseline  
- Random lightning bursts  
- Variable intensity & interval  
- Designed for acrylic/cloud diffusion  
- **Goal:** atmospheric motion and subtle chaos

### 2. Core Breathing Engine (12–13)
- Fade-in → hold → fade-out curve  
- Modes: Pink / Amethyst / White / Gem-tone  
- Per-cycle brightness scaling  
- Mode switching only at blackout  
- **Goal:** rhythmic “energy core” effect

<br>
<img src="https://via.placeholder.com/900x1/eeeeee/eeeeee">
<br>

## 🛠️ Technology Stack

### Hardware
- Arduino Nano Every  
- 14× GRBW SK6812 NeoPixel LEDs  
- 5 V regulated rail  

### Software
- PlatformIO (Arduino)  
- Adafruit NeoPixel library  
- Non-blocking timing  
- State/mode engine  

### Tools
- VS Code + PlatformIO  
- GitHub SSH workflow  

<br>
<img src="https://via.placeholder.com/900x1/eeeeee/eeeeee">
<br>

## 🖼️ Gallery (Optional)

Add photos here:

![Front view](images/jinx_front.jpg)  
![Cloud lighting](images/jinx_clouds.jpg)  
![Internal wiring](images/jinx_wiring.jpg)

