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
    if (dt <= 0.0f) dt = 0.01f;  // Prevent division by zero
    lastTime = now;

    // Setpoints from RC (mapped to -500..500)
    float targetRoll = cmd.roll * 0.1f;    // Scale down for stability
    float targetPitch = cmd.pitch * 0.1f;
    float targetYaw = cmd.yaw * 0.1f;

    // Errors
    float errorRoll = targetRoll - currentRoll;
    float errorPitch = targetPitch - currentPitch;
    float errorYaw = targetYaw - currentYaw;

    // Integrals
    integralRoll += errorRoll * dt;
    integralPitch += errorPitch * dt;
    integralYaw += errorYaw * dt;

    // Derivatives
    float derivativeRoll = (errorRoll - prevErrorRoll) / dt;
    float derivativePitch = (errorPitch - prevErrorPitch) / dt;
    float derivativeYaw = (errorYaw - prevErrorYaw) / dt;

    // PID calculations
    float outputRoll = Kp_roll * errorRoll + Ki_roll * integralRoll + Kd_roll * derivativeRoll;
    float outputPitch = Kp_pitch * errorPitch + Ki_pitch * integralPitch + Kd_pitch * derivativePitch;
    float outputYaw = Kp_yaw * errorYaw + Ki_yaw * integralYaw + Kd_yaw * derivativeYaw;

    // Save errors for next cycle
    prevErrorRoll = errorRoll;
    prevErrorPitch = errorPitch;
    prevErrorYaw = errorYaw;

    PIDOutput pid;
    pid.roll = outputRoll;
    pid.pitch = outputPitch;
    pid.yaw = outputYaw;

    return pid;
}
