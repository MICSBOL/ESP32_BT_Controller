#include <Arduino.h>
#include <Wire.h>

/* =====================================================
   I2C ADDRESSES
   ===================================================== */
#define I2C_ADDR_TEMP 0x48
#define I2C_ADDR_IMU  0x68

/* =====================================================
   INIT
   Call this once from boardInit()
   ===================================================== */
void i2cSensorsInit() {
    // Nothing special for now
    // (IMU init could be added later if needed)
}

/* =====================================================
   READ TEMPERATURE SENSOR
   ===================================================== */
uint16_t i2cReadTemp() {

    Wire.beginTransmission(I2C_ADDR_TEMP);
    Wire.write(0x00);
    if (Wire.endTransmission() != 0) return 0;

    Wire.requestFrom(I2C_ADDR_TEMP, (uint8_t)2);

    if (Wire.available() < 2) return 0;

    uint16_t value = (Wire.read() << 8) | Wire.read();
    return value;
}

/* =====================================================
   READ IMU (ACCEL ONLY)
   Example: MPU6050
   ===================================================== */
void i2cReadIMU(int16_t &ax, int16_t &ay, int16_t &az) {

    ax = ay = az = 0;

    Wire.beginTransmission(I2C_ADDR_IMU);
    Wire.write(0x3B);  // ACCEL_XOUT_H
    if (Wire.endTransmission(false) != 0) return;

    Wire.requestFrom(I2C_ADDR_IMU, (uint8_t)6);

    if (Wire.available() < 6) return;

    ax = (Wire.read() << 8) | Wire.read();
    ay = (Wire.read() << 8) | Wire.read();
    az = (Wire.read() << 8) | Wire.read();
}