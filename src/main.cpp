#include <Arduino.h>
#include "sensor_fusion.h"
#include "receiver.h"
#include "pid.h"
#include "motors.h"

Orientation orient;
Commands cmd;
PIDOutput pidOut;

void setup() {
	Serial.begin(115200);
	delay(1000);
	Serial.println("Drone Control System Starting");

	initSensorFusion();   // Initialize MPU9250 + Compass
	initReceiver();       // Initialize iBus RX (Serial2)
	initPID();            // Initialize PID (tuning params inside pid.cpp)
	initMotors();         // Setup PWM channels + arm ESCs

	Serial.println("System Ready. Waiting for RC inputs...");
}

void loop() {
	// 1. Update Orientation
	orient = getOrientation();  // pitch, roll, yaw in degrees

	// 2. Read RC Inputs
	cmd = readReceiver();  // throttle [0-1000], pitch/roll/yaw [-500 to 500]

	// 3. Compute PID Output
	pidOut = computePID(orient.roll, orient.pitch, orient.yaw, cmd);  // PID [-500 to 500]

	// 4. Motor Mixing & PWM Output
	setMotorSpeeds(cmd.throttle, pidOut.roll, pidOut.pitch, pidOut.yaw);

	delay(20); 
}