#include "Particle.h"

SerialLogHandler logHandler;
SYSTEM_THREAD(ENABLED);

const pin_t blinkPin = D7;
const std::chrono::milliseconds blinkPeriod = 500ms;
bool blinkState = false;
unsigned blinkLastToggle = 0;

void setup() {
    pinMode(blinkPin, OUTPUT);
    digitalWrite(blinkPin, false);
}

void loop() {
    if (millis() - blinkLastToggle >= blinkPeriod.count()) {
        blinkLastToggle = millis();
        blinkState = !blinkState;
        digitalWrite(blinkPin, blinkState);
    }
}