#ifndef PID_H
#define PID_H

#include "receiver.h"

struct PIDOutput {
    float roll;
    float pitch;
    float yaw;
};

void initPID();
PIDOutput computePID(float currentRoll, float currentPitch, float currentYaw, Commands cmd);

#endif
