#include <Arduino.h>
#include "sensor_fusion.h"

void runSensorFusionTest() {
    initSensorFusion();

    while (true) {
        Orientation orient = getOrientation();

        Serial.print("Pitch: "); Serial.print(orient.pitch, 2);
        Serial.print("° | Roll: "); Serial.print(orient.roll, 2);
        Serial.println("°");

        delay(100);
    }
}
