// ESC & motor PWM control functions

#ifndef MOTORS_H
#define MOTORS_H

void initMotors();
void calibrateESCs();
void setMotorSpeeds(int throttle, float pidRoll, float pidPitch, float pidYaw);
void stopMotors();

#endif
