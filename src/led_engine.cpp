#include "led_engine.h"

// -------------------------------------------
// USER SETTINGS
// -------------------------------------------
#define ALT_COLOR_CHANCE    10
#define RANDOM_COLOR_CHANCE 5
#define HALF_BRIGHT_CHANCE  10
// -------------------------------------------

#define LED_PIN        4
#define NUM_LEDS       14
#define COLOR_ORDER    NEO_GRBW
#define BRIGHTNESS     255

#define PINK_MIN       10
#define PINK_MAX       255
#define PINK_FADE_TIME 3000
#define PINK_HOLD_TIME 2000
#define PINK_OFF_TIME  5000

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, COLOR_ORDER + NEO_KHZ800);

// ----------------------------------------------------------
// BEGIN
// ----------------------------------------------------------
void LedEngine::begin() {
    strip.begin();
    strip.setBrightness(BRIGHTNESS);
    strip.show();
    Serial.begin(115200);

    for (int i = 0; i < 12; i++)
        nextSparkleTime[i] = millis() + random(200, 2000);

    rollNewMode();
}

// ----------------------------------------------------------
// UPDATE LOOP
// ----------------------------------------------------------
void LedEngine::update() {
    unsigned long now = millis();

    updateSparkles(now);
    updateBreathing(now);

    strip.show();
    delay(20);
}

// ----------------------------------------------------------
// SPARKLES
// ----------------------------------------------------------
void LedEngine::updateSparkles(unsigned long now) {

    for (int i = 0; i < 12; i++) {

        uint32_t c = strip.getPixelColor(i);
        uint8_t r = ((c >> 16) & 0xFF) * 0.7;
        uint8_t g = ((c >>  8) & 0xFF) * 0.7;
        uint8_t b =  (c        & 0xFF) * 0.7;
        uint8_t w = ((c >> 24) & 0xFF) * 0.7;

        strip.setPixelColor(i, strip.Color(r, g, b, w));

        if (now >= nextSparkleTime[i]) {
            int m = random(6);
            uint8_t v = random(60, 256);

            if (m == 0)
                strip.setPixelColor(i, strip.Color(0, 0, 0, 255));
            else {
                switch(m) {
                    case 1: strip.setPixelColor(i, strip.Color(v, 0, 0, 0)); break;
                    case 2: strip.setPixelColor(i, strip.Color(0, v, 0, 0)); break;
                    case 3: strip.setPixelColor(i, strip.Color(0, 0, v, 0)); break;
                    case 4: strip.setPixelColor(i, strip.Color(v, v, 0, 0)); break;
                    case 5: strip.setPixelColor(i, strip.Color(v, 0, v, 0)); break;
                }
            }

            nextSparkleTime[i] = now + random(200, 3000);
        }
    }
}

// ----------------------------------------------------------
// BREATHING CURVE ENGINE
// ----------------------------------------------------------
void LedEngine::updateBreathing(unsigned long now) {

    unsigned long cycleTime =
        PINK_FADE_TIME + PINK_HOLD_TIME + PINK_OFF_TIME;

    unsigned long phase = now % cycleTime;
    uint8_t breathLevel = 0;

    if (phase < PINK_FADE_TIME / 2) {
        breathLevel =
            PINK_MIN +
            (PINK_MAX - PINK_MIN) *
            ((float)phase / (PINK_FADE_TIME / 2));
    }
    else if (phase < (PINK_FADE_TIME / 2 + PINK_HOLD_TIME)) {
        breathLevel = PINK_MAX;
    }
    else if (phase < (PINK_FADE_TIME + PINK_HOLD_TIME)) {
        breathLevel =
            PINK_MIN +
            (PINK_MAX - PINK_MIN) *
            (1.0 - ((float)(phase - (PINK_FADE_TIME / 2 + PINK_HOLD_TIME)) /
                    (PINK_FADE_TIME / 2)));
    }
    else {
        breathLevel = 0;
    }

    if (breathLevel == 0)
        cycleRolled = false;

    if (!cycleRolled && breathLevel == 0)
        rollNewMode();

    float scale = (breathLevel / 255.0f) * cycleBrightness;

    uint8_t outR = modeR * scale;
    uint8_t outG = modeG * scale;
    uint8_t outB = modeB * scale;
    uint8_t outW = modeW * scale;

    strip.setPixelColor(12, strip.Color(outR, outG, outB, outW));
    strip.setPixelColor(13, strip.Color(outR, outG, outB, outW));
}

// ----------------------------------------------------------
// MODE ROLLER
// ----------------------------------------------------------
void LedEngine::rollNewMode() {

    int cRoll = random(100);
    int bRoll = random(100);

    if (cRoll < ALT_COLOR_CHANCE)
        currentMode = 1;
    else if (cRoll < ALT_COLOR_CHANCE + RANDOM_COLOR_CHANCE)
        currentMode = 3;
    else
        currentMode = 0;

    cycleBrightness =
        (bRoll < HALF_BRIGHT_CHANCE) ? 0.5 : 1.0;

    if (currentMode == 0) {
        modeR = 255;
        modeG = 0;
        modeB = 170;
        modeW = 0;
    }
    else if (currentMode == 1) {
        if (random(2) == 0) {
            modeR = 30;
            modeG = 0;
            modeB = 180;
            modeW = 0;
        } else {
            modeR = 0;
            modeG = 0;
            modeB = 0;
            modeW = 255;
        }
    }
    else if (currentMode == 3) {
        switch (random(14)) {
            case 0: modeR = 255; modeG = 0;   modeB = 0;   break;
            case 1: modeR = 0;   modeG = 255; modeB = 0;   break;
            case 2: modeR = 0;   modeG = 0;   modeB = 255; break;
            case 3: modeR = 255; modeG = 255; modeB = 0;   break;
            case 4: modeR = 255; modeG = 0;   modeB = 255; break;
            case 5: modeR = 0;   modeG = 255; modeB = 255; break;
            case 6: modeR = 255; modeG = 80;  modeB = 0;   break;
            case 7: modeR = 0;   modeG = 180; modeB = 120; break;
            case 8: modeR = 255; modeG = 30;  modeB = 100; break;
            case 9: modeR = 255; modeG = 160; modeB = 0;   break;
            case 10: modeR = 80; modeG = 160; modeB = 255; break;
            case 11: modeR = 0;   modeG = 80; modeB = 255; break;
            case 12: modeR = 0;   modeG = 255; modeB = 60; break;
            case 13: modeR = 255; modeG = 0;   modeB = 120; break;
        }
        modeW = 0;
    }

    cycleRolled = true;
}
