#pragma once
#include <Adafruit_NeoPixel.h>

class LedEngine {
public:
    void begin();
    void update();

private:
    void rollNewMode();
    void updateSparkles(unsigned long now);
    void updateBreathing(unsigned long now);

    // state
    bool cycleRolled = false;
    int currentMode = 0;
    float cycleBrightness = 1.0;

    uint8_t modeR = 0, modeG = 0, modeB = 0, modeW = 0;
    unsigned long nextSparkleTime[12];
};
