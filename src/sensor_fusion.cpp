#include "sensor_fusion.h"
#include <Wire.h>
#include <MPU9250_asukiaaa.h>
#include <QMC5883LCompass.h>

MPU9250_asukiaaa imuSensor;
QMC5883LCompass compass;

float pitch = 0, roll = 0;
unsigned long lastUpdate = 0;
const float alpha = 0.98;

void initSensorFusion() {
    Wire.begin();
    Serial.println("Wire.begin() done.");

    imuSensor.setWire(&Wire);
    imuSensor.beginAccel();
    imuSensor.beginGyro();

    // Initialize QMC5883L Compass
    compass.init();
    compass.setCalibrationOffsets(-281, -52, 149);

    delay(10);  
    Serial.println("QMC5883L Compass initialized.");

    lastUpdate = millis();
    Serial.println("Sensor Fusion Ready.");
}

Orientation getOrientation() {
    imuSensor.accelUpdate();
    imuSensor.gyroUpdate();

    unsigned long now = millis();
    float dt = (now - lastUpdate) / 1000.0f;
    lastUpdate = now;

    // Accelerometer angles
    float accPitch = atan2(imuSensor.accelY(), imuSensor.accelZ()) * 180.0 / PI;
    float accRoll = atan2(-imuSensor.accelX(), imuSensor.accelZ()) * 180.0 / PI;

    // Gyroscope integration
    pitch = alpha * (pitch + imuSensor.gyroX() * dt) + (1 - alpha) * accPitch;
    roll = alpha * (roll  + imuSensor.gyroY() * dt) + (1 - alpha) * accRoll;

    // Yaw from Compass
    compass.read();
    int yaw = compass.getAzimuth();  
    if (yaw < 0) yaw += 360; // Yaw in degrees (0-360)

    Orientation orient;
    orient.pitch = pitch;
    orient.roll = roll;
    orient.yaw = yaw;
    return orient;
}
