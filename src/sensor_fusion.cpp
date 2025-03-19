#include "sensor_fusion.h"

Orientation complementaryFilter(float gyroX, float gyroY, float gyroZ, 
                               float accX, float accY, float accZ, 
                               float magX, float magY, float magZ, 
                               float dt) {
    // TODO: Implement Complementary filter logic here
    Orientation ori = {0,0,0};
    return ori;
}
