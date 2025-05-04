#include "receiver.h"
#include <Arduino.h>
#include <HardwareSerial.h>
#include <IBusBM.h>

IBusBM ibus;
#define IBUS_RX_PIN 16
#define IBUS_SERIAL Serial2

#define CH_ROLL 0
#define CH_PITCH 1
#define CH_THROTTLE 2
#define CH_YAW 3

void initReceiver() {
    IBUS_SERIAL.begin(115200, SERIAL_8N1, IBUS_RX_PIN, -1);
    ibus.begin(IBUS_SERIAL);
}

Commands readReceiver() {
    ibus.loop();  

    Commands cmd;

    int rawThrottle = ibus.readChannel(CH_THROTTLE);
    int rawPitch = ibus.readChannel(CH_PITCH);
    int rawRoll = ibus.readChannel(CH_ROLL);
    int rawYaw = ibus.readChannel(CH_YAW);

    if (rawThrottle < 900) rawThrottle = 1000;
    if (rawPitch < 900) rawPitch = 1500;
    if (rawRoll < 900) rawRoll = 1500;
    if (rawYaw < 900) rawYaw = 1500;

    cmd.throttle = constrain(map(rawThrottle, 1000, 2000, 0, 1000), 0, 1000);
    cmd.pitch = constrain(map(rawPitch, 1000, 2000, -500, 500), -500, 500);
    cmd.roll = constrain(map(rawRoll, 1000, 2000, -500, 500), -500, 500);
    cmd.yaw = constrain(map(rawYaw, 1000, 2000, -500, 500), -500, 500);

    return cmd;
}
