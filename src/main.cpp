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

	initSensorFusion();   // Initialize MPU6500 + Compass
	initReceiver();       // Initialize iBus RX 
	initPID();            // Initialize PID 
	initMotors();         // Setup PWM channels + arm ESCs

	Serial.println("System Ready. Waiting for RC inputs...");
}

void loop() {
	// 1. Update Orientation
	orient = getOrientation();  // pitch, roll, yaw in degrees

	// 2. Read RC Inputs
	cmd = readReceiver();  

	// 3. Compute PID Output
	pidOut = computePID(orient.roll, orient.pitch, orient.yaw, cmd); 

	// 4. Motor Mixing & PWM Output
	setMotorSpeeds(cmd.throttle, pidOut.roll, pidOut.pitch, pidOut.yaw);

	delay(20); 
}
