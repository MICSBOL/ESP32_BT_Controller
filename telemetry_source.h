#ifndef TELEMETRY_SOURCE_H
#define TELEMETRY_SOURCE_H

#include <Arduino.h>

// PANEL
uint16_t getPanelLeft();
uint16_t getPanelRight();

// INDICATOR
uint8_t getIndicatorAnalog();
uint8_t getIndicatorBattery();

// PLOT
uint8_t getPlot1();
uint8_t getPlot2();
uint8_t getPlot3();

// Debug serial input handler
void telemetrySourceUpdate();

uint8_t getIndicatorDigitalMask();
void telemetrySourceUpdate();
#endif