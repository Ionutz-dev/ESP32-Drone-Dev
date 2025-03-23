#ifndef SENSOR_FUSION_H
#define SENSOR_FUSION_H

struct Orientation {
    float pitch;
    float roll;
    float yaw;
};

void initSensorFusion();
Orientation getOrientation();

#endif
