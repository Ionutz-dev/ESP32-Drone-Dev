#include "pid.h"
#include <Arduino.h>

// PID gains 
const float Kp_roll = 1.8;
const float Ki_roll = 0.02;
const float Kd_roll = 0.04;

const float Kp_pitch = 1.8;
const float Ki_pitch = 0.02;
const float Kd_pitch = 0.04;

const float Kp_yaw = 2.0;
const float Ki_yaw = 0.05;
const float Kd_yaw = 0.0;

// PID state variables
float prevErrorRoll = 0, prevErrorPitch = 0, prevErrorYaw = 0;
float integralRoll = 0, integralPitch = 0, integralYaw = 0;

unsigned long lastTime = 0;

void initPID() {
    lastTime = millis();
    prevErrorRoll = prevErrorPitch = prevErrorYaw = 0;
    integralRoll = integralPitch = integralYaw = 0;
}

PIDOutput computePID(float currentRoll, float currentPitch, float currentYaw, Commands cmd) {
    unsigned long now = millis();
    float dt = (now - lastTime) / 1000.0f;  // seconds
    if (dt <= 0.0f) dt = 0.01f;
    lastTime = now;

    // RC setpoints (-50 to 50 degrees)
    float targetRoll = cmd.roll * 0.1f;
    float targetPitch = cmd.pitch * 0.1f;
    float targetYaw = cmd.yaw * 0.1f;

    // Errors
    float errorRoll = targetRoll - currentRoll;
    float errorPitch = targetPitch - currentPitch;
    float errorYaw = targetYaw - currentYaw;

    // Reset PID state if throttle low
    if (cmd.throttle < 50) {
        integralRoll = integralPitch = integralYaw = 0;
        prevErrorRoll = prevErrorPitch = prevErrorYaw = 0;
    }

    // Integrals
    integralRoll += errorRoll * dt;
    integralPitch += errorPitch * dt;
    integralYaw += errorYaw * dt;

    // Derivatives
    float derivativeRoll = (errorRoll - prevErrorRoll) / dt;
    float derivativePitch = (errorPitch - prevErrorPitch) / dt;
    float derivativeYaw = (errorYaw - prevErrorYaw) / dt;

    // PID outputs
    float outputRoll = Kp_roll * errorRoll + Ki_roll * integralRoll + Kd_roll * derivativeRoll;
    float outputPitch = Kp_pitch * errorPitch + Ki_pitch * integralPitch + Kd_pitch * derivativePitch;
    float outputYaw = Kp_yaw * errorYaw + Ki_yaw * integralYaw + Kd_yaw * derivativeYaw;

    // Clamp PID outputs
    outputRoll = constrain(outputRoll, -500, 500);
    outputPitch = constrain(outputPitch, -500, 500);
    outputYaw = constrain(outputYaw, -500, 500);

    // Store for next loop
    prevErrorRoll = errorRoll;
    prevErrorPitch = errorPitch;
    prevErrorYaw = errorYaw;

    PIDOutput pid;
    pid.roll = outputRoll;
    pid.pitch = outputPitch;
    pid.yaw = outputYaw;

    return pid;
}


