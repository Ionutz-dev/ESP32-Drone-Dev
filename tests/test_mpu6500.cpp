#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();

    Serial.println("Initializing MPU6500...");

    if (!mpu.begin(0x68)) {
        Serial.println("Could not find MPU6500! Check connections.");
        return;
    }

    Serial.println("MPU6500 Ready!");

    mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    delay(100);
}

void loop() {
    sensors_event_t accel, gyro, temp;
    mpu.getEvent(&accel, &gyro, &temp);

    Serial.print("Accelerometer X: "); Serial.print(accel.acceleration.x);
    Serial.print(" Y: "); Serial.print(accel.acceleration.y);
    Serial.print(" Z: "); Serial.println(accel.acceleration.z);

    Serial.print("Gyroscope X: "); Serial.print(gyro.gyro.x);
    Serial.print(" Y: "); Serial.print(gyro.gyro.y);
    Serial.print(" Z: "); Serial.println(gyro.gyro.z);

    Serial.println("--------------------------------------------------");
    delay(500);
}
