#ifndef I2C_SENSORS_H
#define I2C_SENSORS_H

#include <Arduino.h>

uint16_t i2cReadTemp();
void i2cReadIMU(int16_t &ax, int16_t &ay, int16_t &az);

#endif
