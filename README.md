# ESP32 Drone Flight Controller

## 📖 **Overview**

**ESP32-Drone** is a DIY drone project using an **ESP32-WROOM-32** microcontroller as a fully custom flight controller. It involves detailed integration and programming of sensors, motor controllers (ESCs), remote control receivers, and stabilization algorithms to achieve controlled drone flight.

## 🛠️ **Key Features**

- ⚙️ **Custom ESP32 Flight Controller** (fully programmable using VS Code & PlatformIO)
- 📡 **Sensors Integrated**:
  - **MPU6500** (6-axis Gyroscope & Accelerometer)
  - **HMC5883L** Magnetometer (heading/direction)
  - **BMP280** Barometric pressure sensor (altitude)
  - **NEO-6M GPS Module** (positioning/navigation)
- 📻 **Remote Control**: FlySky FS-i6X transmitter & FS-iA6B receiver (PWM/iBus)
- 🚁 **Motors & ESC**: 2212 920KV Brushless motors & 30A ESCs controlled via PWM signals.
- 🧭 **PID Stabilization** (in-progress)
- 🔄 **Sensor Fusion Algorithm** (Complementary filter, planned)
- 🧰 **Development Environment**: PlatformIO in Visual Studio Code

## 📋 **Components Used**

| Component                           | Model                             |
| ----------------------------------- | --------------------------------- |
| Microcontroller (Flight Controller) | ESP32-WROOM-32                    |
| Frame                               | F450 Quadcopter                   |
| Motors                              | DJI 2212 920KV                    |
| ESCs                                | 30A                               |
| Propellers                          | 1045 (10") CW & CCW               |
| Battery                             | LiPo 4S (14.8V, 1550mAh)          |
| Power Distribution                  | Matek PDB BEC 5V/12V              |
| Transmitter & Receiver              | FlySky FS-i6X + FS-iA6B           |
| Sensors                             | MPU6500, HMC5883L, BMP280, NEO-6M |

## 🚀 **Current Progress**

- ✅ **ESP32 initial setup (PlatformIO environment)**
- ✅ **Sensor Integration** _(IMU, GPS, Barometer, Magnetometer)_
- ✅ **Motor & ESC Testing (PWM signals tested successfully)**
- ⏳ **Remote control integration (in-progress)**
- ⏳ **PID Stabilization (next stage)**
- ⏳ **Sensor Fusion algorithm implementation**

## 📂 **Project Structure**

```
ESP32-Drone/
│
├── lib/
│   ├── MPU6500/                 # IMU sensor integration
│   ├── HMC5883L/                # Magnetometer
│   ├── BMP280/                  # Altitude sensor
│   └── GPS-Neo6M/               # GPS positioning
│
├── src/
│   ├── main.cpp                 # Main entry point
│   ├── motors.cpp/h             # ESC & Motor control logic
│   ├── receiver.cpp/h           # FlySky receiver communication
│   ├── stabilization.cpp/h      # PID control algorithms (in-progress)
│   └── sensor_fusion.cpp/h      # Complementary filter (planned)
│
├── platformio.ini               # PlatformIO project configuration
└── README.md                    # Project documentation
```

## 🔧 **How to Run & Test the Project**

### **Step 1: Development Setup**

- Install [VS Code](https://code.visualstudio.com/) and [PlatformIO extension](https://platformio.org/platformio-ide).
- Clone and open this project in VS Code.

```bash
git clone <your-repo-link>
cd ESP32-Drone
```

### **Build & Upload (PlatformIO)**

- Connect ESP32 via USB.
- Click **PlatformIO → Build** and then **PlatformIO → Upload**.

### **Serial Monitor (for debugging)**

Use PlatformIO's built-in Serial Monitor:

```bash
platformio device monitor
```

## 📌 **Next Steps & Planned Improvements**

- Implement real-time sensor fusion (Complementary filter).
- PID stabilization algorithm development.
- Conduct initial controlled hover flight tests.
- Integrate advanced navigation (GPS Waypoint navigation, Return-to-Home).

_Feel free to reach out if you have questions or feedback about this project!_
