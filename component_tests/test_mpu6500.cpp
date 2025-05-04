#include <Arduino.h>
#include <Wire.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa imu;

void setup() {
    Serial.begin(115200);
    Wire.begin();  

    imu.setWire(&Wire);
    imu.beginAccel();
    imu.beginGyro();

    Serial.println("Initializing MPU9250 (MPU6500 core)...");
}

void loop() {
    imu.accelUpdate();
    imu.gyroUpdate();

    Serial.print("Accel X: "); Serial.print(imu.accelX());
    Serial.print(" Y: "); Serial.print(imu.accelY());
    Serial.print(" Z: "); Serial.println(imu.accelZ());

    Serial.print("Gyro X: "); Serial.print(imu.gyroX());
    Serial.print(" Y: "); Serial.print(imu.gyroY());
    Serial.print(" Z: "); Serial.println(imu.gyroZ());

    Serial.println("--------------------------------------------------");
    delay(500);
}
