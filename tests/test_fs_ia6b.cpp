#include <HardwareSerial.h>
#include <IBusBM.h>

IBusBM ibus;  // Create iBUS object

#define IBUS_PIN 16  // iBUS from FS-iA6B is connected to GPIO16

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, IBUS_PIN, -1);  // Use UART2 for iBUS communication
  ibus.begin(Serial2);  // Initialize iBUS

  Serial.println("Waiting for FS-iA6B Receiver Data...");
}

void loop() {
  ibus.loop();  // Required for processing iBUS signals

  Serial.print("CH1: "); Serial.print(ibus.readChannel(0));
  Serial.print(" CH2: "); Serial.print(ibus.readChannel(1));
  Serial.print(" CH3: "); Serial.print(ibus.readChannel(2));
  Serial.print(" CH4: "); Serial.print(ibus.readChannel(3));
  Serial.print(" CH5: "); Serial.print(ibus.readChannel(4));
  Serial.print(" CH6: "); Serial.println(ibus.readChannel(5));

  delay(100);
}
