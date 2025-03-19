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
- 📻 **Remote Control**: FlySky FS-i6 transmitter & FS-iA6B receiver (PWM/iBus)
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
| Transmitter & Receiver              | FlySky FS-i6 + FS-iA6B            |
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
ESP32-Drone-Dev/
│
├── include/                          # Header files
│   └── README.md
│
├── src/                              # Main application source code
│   └── main.cpp                      # Main entry point
│
├── test/                             # General testing directory
│   └── README.md
│
├── component_tests/                  # Individual hardware tests
│   ├── test_bmp280.cpp               # BMP280 sensor tests
│   ├── test_esc_motor.cpp            # ESC & Motor PWM tests
│   ├── test_fs_ia6b.cpp              # FlySky FS-iA6B receiver tests
│   ├── test_gps_neo6m.cpp            # GPS sensor tests
│   ├── test_hmc5883l.cpp             # Magnetometer tests
│   └── test_mpu6500.cpp              # IMU sensor tests
│
├── .gitignore                        # Git ignore rules
├── platformio.ini                    # PlatformIO project configuration
└── README.md                         # Project documentation
```

## 🔧 **How to Run & Test the Project**

### **Step 1: Development Setup**

- Install [VS Code](https://code.visualstudio.com/) and [PlatformIO extension](https://platformio.org/platformio-ide).
- Clone and open this project in VS Code.

```bash
git clone https://github.com/Ionutz-dev/ESP32-Drone-Dev.git
cd ESP32-Drone-Dev
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
