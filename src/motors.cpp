#include "motors.h"
#include <Arduino.h>

const int escPins[4] = {25, 26, 32, 33}; 
const int pwmChannels[4] = {0, 1, 2, 3}; 

const int freq = 50;         // ESCs expect 50Hz
const int resolution = 16;   // 16-bit PWM

const int minDuty = 3276;    // 1000µs PWM (stopped)
const int maxDuty = 6553;    // 2000µs PWM (full throttle)

const int minSpinDuty[4] = {
    4100, // Motor 1 (FR - CCW)
    4100, // Motor 2 (BR - CW)
    4100, // Motor 3 (BL - CCW)
    4100  // Motor 4 (FL - CW)
};

void initMotors() {
    for (int i = 0; i < 4; i++) {
        ledcSetup(pwmChannels[i], freq, resolution);
        ledcAttachPin(escPins[i], pwmChannels[i]);
        ledcWrite(pwmChannels[i], minDuty);  
    }

    delay(3000); 
}

void calibrateESCs() {
    Serial.println("ESC Calibration: Sending MAX throttle");
    for (int i = 0; i < 4; i++) {
        ledcWrite(pwmChannels[i], maxDuty); 
    }
    delay(2000); 

    Serial.println("Sending MIN throttle to complete calibration...");
    for (int i = 0; i < 4; i++) {
        ledcWrite(pwmChannels[i], minDuty); 
    }
    delay(3000); 
    Serial.println("ESC Calibration Complete.");
}

void setMotorSpeeds(int throttle, float pidRoll, float pidPitch, float pidYaw) {
    if (throttle < 50) {
        stopMotors();
        return;
    }

    float motorCommands[4];
    motorCommands[0] = throttle + pidRoll - pidPitch + pidYaw;  // M1 (FR - CCW)
    motorCommands[1] = throttle + pidRoll + pidPitch - pidYaw;  // M2 (BR - CW)
    motorCommands[2] = throttle - pidRoll + pidPitch + pidYaw;  // M3 (BL - CCW)
    motorCommands[3] = throttle - pidRoll - pidPitch - pidYaw;  // M4 (FL - CW)

    for (int i = 0; i < 4; i++) {
        int mappedDuty = map(motorCommands[i], 0, 1000, minDuty, maxDuty);
        mappedDuty = constrain(mappedDuty, minSpinDuty[i], maxDuty);
        ledcWrite(pwmChannels[i], mappedDuty);
    }
}

void stopMotors() {
    for (int i = 0; i < 4; i++) {
        ledcWrite(pwmChannels[i], minDuty); 
    }
    Serial.println("Motors Stopped.");
}
