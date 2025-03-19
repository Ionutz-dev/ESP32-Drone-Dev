#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;  // Create BMP280 object

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // Set ESP32 I2C pins
  Serial.println("Initializing BMP280 Sensor...");

  if (!bmp.begin(0x76)) {  // Default BMP280 I2C address is 0x76
    Serial.println("❌ BMP280 not found! Check wiring.");
    while (1);  // Halt execution
  }

  Serial.println("✅ BMP280 Ready!");
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" °C");

  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure() / 100.0);  // Convert to hPa
  Serial.println(" hPa");

  Serial.print("Approx. Altitude: ");
  Serial.print(bmp.readAltitude(1013.25));  // Reference sea-level pressure in hPa
  Serial.println(" m");

  Serial.println("--------------------------------------------------");
  delay(1000);
}
