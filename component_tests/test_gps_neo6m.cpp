#include <HardwareSerial.h>
#include <TinyGPSPlus.h>

// Define UART2 for GPS communication
HardwareSerial GPS_Serial(2);
TinyGPSPlus gps;

void setup() {
    Serial.begin(115200);    
    GPS_Serial.begin(9600, SERIAL_8N1, 16, 17);  // Start GPS UART2 on GPIO16 (RX) & GPIO17 (TX)

    Serial.println("Initializing NEO-6M GPS...");
}

void loop() {
    while (GPS_Serial.available() > 0) {
        gps.encode(GPS_Serial.read()); 

        if (gps.location.isUpdated()) {
            Serial.print("Latitude: "); Serial.print(gps.location.lat(), 6);
            Serial.print(" Longitude: "); Serial.print(gps.location.lng(), 6);
            Serial.print(" Altitude: "); Serial.print(gps.altitude.meters());
            Serial.print(" m Speed: "); Serial.print(gps.speed.kmph());
            Serial.println(" km/h");
        }
    }
}
