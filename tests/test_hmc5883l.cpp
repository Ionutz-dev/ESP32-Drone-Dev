#include <Wire.h>
#include <QMC5883LCompass.h>

QMC5883LCompass qmc;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);   // ESP32 I2C pins
  Wire.setClock(100000); // Reduce I2C speed to 100kHz for stability

  Serial.println("Initializing QMC5883L Magnetometer...");
  qmc.init();  // Initialize QMC5883L

  Serial.println("✅ QMC5883L Ready!");
}

void loop() {
  qmc.read();  // Read magnetometer data

  int x = qmc.getX();
  int y = qmc.getY();
  int z = qmc.getZ();

  Serial.print("Magnetometer X: "); Serial.print(x);
  Serial.print(" Y: "); Serial.print(y);
  Serial.print(" Z: "); Serial.println(z);

  Serial.println("--------------------------------------------------");
  delay(500);
}
