#include <Arduino.h>

const int escPins[4] = {25, 26, 32, 33};      // Your ESC pins
const int pwmChannels[4] = {0, 1, 2, 3};      // PWM channels
const int freq = 50;
const int resolution = 16;

const int minDuty = 3276;   // 1000µs
const int maxDuty = 6553;   // 2000µs

void setup() {
    Serial.begin(115200);
    delay(2000);
    Serial.println("=== Motor Spin Threshold Calibration ===");

    for (int i = 0; i < 4; i++) {
        ledcSetup(pwmChannels[i], freq, resolution);
        ledcAttachPin(escPins[i], pwmChannels[i]);
        ledcWrite(pwmChannels[i], minDuty);
    }

    Serial.println("ESCs armed. Starting calibration in 3 seconds...");
    delay(3000);
}

void loop() {
    static int currentMotor = 0;
    static int duty = minDuty;
    static bool waitForInput = false;

    if (currentMotor >= 4) {
        Serial.println("All motors tested.");
        while (true); 
    }

    if (!waitForInput) {
        currentMotor = 1;
        Serial.print("Motor ");
        Serial.print(currentMotor + 1);
        Serial.print(" | Duty = ");
        Serial.println(duty);

        ledcWrite(pwmChannels[currentMotor], duty);
        waitForInput = true;
        Serial.println("Does motor start spinning? Type any key in Serial Monitor to continue...");
    }

    if (Serial.available()) {
        Serial.read();
        duty += 50;

        if (duty > maxDuty) {
        Serial.println("Max duty reached. Moving to next motor...");
        ledcWrite(pwmChannels[currentMotor], minDuty);
        duty = minDuty;
        currentMotor++;
        }

        waitForInput = false;
    }
}
