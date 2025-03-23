#include <Arduino.h>
#include "receiver.h"

void setup() {
  Serial.begin(115200);
  initReceiver();
  Serial.println("IBUS Receiver Test Ready...");
}

void loop() {
  Commands cmd = readReceiver();

  Serial.print("Throttle: "); Serial.print(cmd.throttle);
  Serial.print(" | Pitch: "); Serial.print(cmd.pitch);
  Serial.print(" | Roll: "); Serial.print(cmd.roll);
  Serial.print(" | Yaw: "); Serial.println(cmd.yaw);

  delay(200);  // Adjust for faster/slower output
}
