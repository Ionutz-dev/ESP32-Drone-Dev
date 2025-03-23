// #include <Arduino.h>

// const int escPin = 25; // ESC signal pin
// const int pwmChannel = 0;
// const int freq = 50;  // 50Hz for ESCs
// const int resolution = 16; // 16-bit resolution

// const int minDuty = 3276;  // ~1000us pulse (stops motor)
// const int midDuty = 4000;  // ~1200us (slow spin)
// const int maxDuty = 6553;  // ~2000us pulse (full speed)

// void setup() {
//   Serial.begin(115200);
//   ledcSetup(pwmChannel, freq, resolution);
//   ledcAttachPin(escPin, pwmChannel);

//   Serial.println("Motor Test Ready!");
//   ledcWrite(pwmChannel, minDuty);  // Arm ESC at minimum throttle
//   delay(3000);  // Give time for ESC arming beeps
// }

// void loop() {
//   Serial.println("Spinning motor slowly...");
//   ledcWrite(pwmChannel, midDuty);  // Spin motor slowly
//   delay(3000);

//   Serial.println("Stopping motor...");
//   ledcWrite(pwmChannel, minDuty);  // Stop motor
//   delay(3000);
// }

// #include <Arduino.h>

// const int escPins[4] = {25, 26, 32, 33}; // ESC signal pins
// const int pwmChannels[4] = {0, 1, 2, 3}; // PWM channels per ESC

// const int freq = 50;           // 50Hz PWM for ESCs
// const int resolution = 16;     // 16-bit resolution

// const int minDuty = 3276;      // ~1000us PWM = motor stop
// const int midDuty = 4000;      // ~1200us PWM = slow spin
// const int maxDuty = 6553;      // ~2000us PWM = full throttle

// void setup() {
//   Serial.begin(115200);
//   Serial.println("Initializing all motors...");

//   // Setup PWM for all ESCs
//   for (int i = 0; i < 4; i++) {
//     ledcSetup(pwmChannels[i], freq, resolution);
//     ledcAttachPin(escPins[i], pwmChannels[i]);
//     ledcWrite(pwmChannels[i], minDuty);  // Arm ESCs with min throttle
//   }

//   delay(3000); // Wait for ESC arming beeps
// }

// void loop() {
//   Serial.println("Spinning all motors slowly...");
//   for (int i = 0; i < 4; i++) {
//     ledcWrite(pwmChannels[i], midDuty); // Spin motors slowly
//   }

//   delay(3000);

//   Serial.println("Stopping all motors...");
//   for (int i = 0; i < 4; i++) {
//     ledcWrite(pwmChannels[i], minDuty); // Stop motors
//   }

//   delay(3000);
// }

// #include <Arduino.h>

// // ESC signal pins (adjust if needed)
// const int escPins[4] = {25, 26, 32, 33}; // ESC1, ESC2, ESC3, ESC4
// const int pwmChannels[4] = {0, 1, 2, 3}; // PWM channels for ESP32

// const int freq = 50;         // 50Hz for ESCs
// const int resolution = 16;   // 16-bit PWM

// // Duty cycle values for 1000µs (min) to 2000µs (max) at 16-bit
// const int minDuty = 3276;    // ~1000us (motor stop)
// const int maxDuty = 6553;    // ~2000us (max throttle)

// // Set your desired motor speeds here (between minDuty and maxDuty)
// int motorSpeeds[4] = {
//   4200,  // ESC1 (Motor 1) - Slow spin
//   4200,  // ESC2 (Motor 2) - Slightly faster
//   4200,  // ESC3 (Motor 3) - Medium speed
//   4200   // ESC4 (Motor 4) - Faster spin
// };

// void setup() {
//   Serial.begin(115200);
//   Serial.println("Initializing 4 ESCs...");

//   // Setup PWM channels and arm ESCs
//   for (int i = 0; i < 4; i++) {
//     ledcSetup(pwmChannels[i], freq, resolution);
//     ledcAttachPin(escPins[i], pwmChannels[i]);
//     ledcWrite(pwmChannels[i], minDuty);  // Arm ESCs at min throttle
//   }

//   delay(3000); // Wait for ESCs to beep and arm
// }

// void loop() {
//   Serial.println("Spinning all motors at different speeds...");
//   for (int i = 0; i < 4; i++) {
//     ledcWrite(pwmChannels[i], motorSpeeds[i]);  // Spin each motor at set speed
//     Serial.print("Motor "); Serial.print(i+1);
//     Serial.print(" Speed Duty: "); Serial.println(motorSpeeds[i]);
//   }

//   delay(3000);  // Run motors for 3 seconds

//   Serial.println("Stopping all motors...");
//   for (int i = 0; i < 4; i++) {
//     ledcWrite(pwmChannels[i], minDuty);  // Stop all motors
//   }

//   delay(3000);  // Wait 3 seconds before repeating
// }

#include <Arduino.h>

// ESC signal pins
const int escPins[4] = {25, 26, 32, 33}; 
const int pwmChannels[4] = {0, 1, 2, 3}; 

const int freq = 50;         // ESCs expect 50Hz
const int resolution = 16;   // 16-bit PWM

const int minDuty = 3276;    // ~1000µs PWM (stopped)
const int maxDuty = 6553;    // ~2000µs PWM (full throttle)

void setup() {
  Serial.begin(115200);
  Serial.println("Smooth Motor Ramp Test Starting...");

  // Setup PWM for each motor and arm ESCs
  for (int i = 0; i < 4; i++) {
    ledcSetup(pwmChannels[i], freq, resolution);
    ledcAttachPin(escPins[i], pwmChannels[i]);
    ledcWrite(pwmChannels[i], minDuty);  // Arm at min throttle
  }

  delay(3000); // Allow ESCs to arm (listen for beeps)
}

// void loop() {
//   Serial.println("Ramping motors UP...");

//   // Ramp up from 4200 to 5000 smoothly
//   for (int duty = 3800; duty <= 5000; duty += 50) {
//     for (int i = 0; i < 4; i++) {
//       ledcWrite(pwmChannels[i], duty);
//     }
//     Serial.print("Duty: "); Serial.println(duty);
//     delay(300); // Smooth ramp (adjust delay for speed)
//   }

//   delay(2000); // Hold at peak speed for 2 sec

//   Serial.println("Ramping motors DOWN...");

//   // Ramp down from 5000 to minDuty
//   for (int duty = 5000; duty >= 3800; duty -= 50) {
//     for (int i = 0; i < 4; i++) {
//       ledcWrite(pwmChannels[i], duty);
//     }
//     Serial.print("Duty: "); Serial.println(duty);
//     delay(300);
//   }

//   Serial.println("Motors stopped. Restarting in 3 sec...");
//   delay(3000);
// }

void loop() {
  Serial.println("Testing individual motor thresholds...");

  for (int motor = 0; motor < 4; motor++) {
    Serial.print("Testing Motor "); Serial.println(motor + 1);

    for (int duty = 3400; duty <= 4200; duty += 50) {
      ledcWrite(pwmChannels[motor], duty);
      Serial.print("Duty: "); Serial.println(duty);
      delay(1000);  // Let motor stabilize at this duty
    }

    // Stop motor
    ledcWrite(pwmChannels[motor], minDuty);
    delay(3000);
  }

  Serial.println("Threshold test complete. Looping again...");
  delay(5000);
}
