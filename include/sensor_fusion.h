// Orientation estimation using Complementary filter

#ifndef SENSOR_FUSION_H
#define SENSOR_FUSION_H

struct Orientation {
    float roll;
    float pitch;
    float yaw;
};

Orientation complementaryFilter(float gyroX, float gyroY, float gyroZ, 
                               float accX, float accY, float accZ, 
                               float magX, float magY, float magZ, 
                               float dt);

#endif
