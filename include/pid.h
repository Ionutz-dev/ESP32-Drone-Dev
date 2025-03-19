// PID controller declarations and tuning parameters

#ifndef PID_H
#define PID_H

struct PIDOutput {
    float roll;
    float pitch;
    float yaw;
};

void initPID();
PIDOutput computePID(float currentRoll, float currentPitch, float currentYaw, Commands cmd);

#endif
