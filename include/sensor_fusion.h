#ifndef SENSOR_FUSION_H
#define SENSOR_FUSION_H

#include <QMC5883LCompass.h>

extern QMC5883LCompass compass;

struct Orientation {
    float pitch;
    float roll;
    float yaw;
};

void initSensorFusion();
Orientation getOrientation();

#endif
