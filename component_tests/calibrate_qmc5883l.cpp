#include <Wire.h>
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void setup() {
	Serial.begin(115200);
	Wire.begin();
	compass.init();
	Serial.println("QMC5883L Calibration Mode");
}

void loop() {
	compass.read();
	Serial.print("X: "); Serial.print(compass.getX());
	Serial.print(" Y: "); Serial.print(compass.getY());
	Serial.print(" Z: "); Serial.println(compass.getZ());
	delay(200);
}
