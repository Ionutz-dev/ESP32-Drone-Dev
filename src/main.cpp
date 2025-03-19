#include <Arduino.h>

// Uncomment ONE of the following to select which sensor test to run:
// #define TEST_MPU6500
// #define TEST_HMC5883L
// #define TEST_BMP280
// #define TEST_GPS_NEO6M
// #define TEST_FS_IA6B
#define TEST_ESC_MOTOR

#ifdef TEST_MPU6500
#include "../tests/test_mpu6500.cpp"  // Load test file
#endif

#ifdef TEST_HMC5883L
#include "../tests/test_hmc5883l.cpp"
#endif

#ifdef TEST_BMP280
#include "../tests/test_bmp280.cpp"
#endif

#ifdef TEST_GPS_NEO6M
#include "../tests/test_gps_neo6m.cpp"
#endif

#ifdef TEST_FS_IA6B
#include "../tests/test_fs_ia6b.cpp"
#endif

#ifdef TEST_ESC_MOTOR
#include "../tests/test_esc_motor.cpp"
#endif
