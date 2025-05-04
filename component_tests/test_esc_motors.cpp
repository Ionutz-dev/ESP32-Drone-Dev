#include <Arduino.h>

// ESC signal pins
const int escPins[4] = {25, 26, 32, 33}; 
const int pwmChannels[4] = {0, 1, 2, 3}; 

const int freq = 50;         // ESCs expect 50Hz
const int resolution = 16;   // 16-bit PWM

const int minDuty = 3276;    // 1000µs PWM (stopped)
const int maxDuty = 6553;    // 2000µs PWM (full throttle)

void setup() {
    Serial.begin(115200);
    Serial.println("Smooth Motor Ramp Test Starting...");

    // Setup PWM for each motor and arm ESCs
    for (int i = 0; i < 4; i++) {
        ledcSetup(pwmChannels[i], freq, resolution);
        ledcAttachPin(escPins[i], pwmChannels[i]);
        ledcWrite(pwmChannels[i], minDuty); 
    }

    delay(3000); 
}

void loop() {
    Serial.println("Testing individual motor thresholds...");

    for (int motor = 0; motor < 4; motor++) {
        Serial.print("Testing Motor "); Serial.println(motor + 1);

        for (int duty = 3400; duty <= 4200; duty += 50) {
          ledcWrite(pwmChannels[motor], duty);
          Serial.print("Duty: "); Serial.println(duty);
          delay(1000);  // Let motor stabilize at this duty
        }

        ledcWrite(pwmChannels[motor], minDuty);
        delay(3000);
    }

    Serial.println("Threshold test complete. Looping again...");
    delay(5000);
}
