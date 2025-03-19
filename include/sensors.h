// Unified sensor initialization & data acquisition

#ifndef SENSORS_H
#define SENSORS_H

struct SensorData {
    float gyroX, gyroY, gyroZ;
    float accX, accY, accZ;
    float magX, magY, magZ;
    float altitude;
    float latitude, longitude;
};

void initSensors();
SensorData readAllSensors();

#endif
