#include <Arduino.h>
#include "pins.h"
#include "mcp_io.h"
#include "pulse.h"
#include "feature_config.h"


/* ================= PWM ================= */
void halSetSteering(uint32_t value) {
  ledcWrite(PIN_PWM_STICK_LX, value);
}

static uint32_t mapMotor0TO2000(uint16_t v) {
  return map(v, 0, 2000, 0, 4095);
}

static uint32_t mapMotor2095TO4095(uint16_t v) {
  return map(v, 2095, 4095, 0, 4095);
}

hw_timer_t *motorTimer = NULL;

volatile uint32_t motorSpeedLeft  = 0;
volatile uint32_t motorSpeedRight = 0;

volatile uint32_t motorTargetLeft  = 0;
volatile uint32_t motorTargetRight = 0;

const uint32_t rampStep = 50;

void halSetMotorLeft(uint32_t value) {

  if (value <= 2000) {
    digitalWrite(PIN_MD_LEFT, LOW);
    motorTargetLeft = mapMotor0TO2000(value);
  } 
  else if (value >= 2095) {
    digitalWrite(PIN_MD_LEFT, HIGH);
    motorTargetLeft = mapMotor2095TO4095(value);
  } 
  else {
    motorTargetLeft = 0;
  }
}


void halSetMotorRight(uint32_t value) {

  if (value <= 2000) {
    digitalWrite(PIN_MD_RIGHT, LOW);
    motorTargetRight = mapMotor0TO2000(value);
  } 
  else if (value >= 2095) {
    digitalWrite(PIN_MD_RIGHT, HIGH);
    motorTargetRight = mapMotor2095TO4095(value);
  } 
  else {
    motorTargetRight = 0;
  }
}

void IRAM_ATTR updateMotors()
{
  // LEFT MOTOR
  if (motorSpeedLeft < motorTargetLeft)
    motorSpeedLeft += rampStep;
  else if (motorSpeedLeft > motorTargetLeft)
    motorSpeedLeft -= rampStep;

  ledcWrite(PIN_PWM_STICK_LY, motorSpeedLeft);

  // RIGHT MOTOR
  if (motorSpeedRight < motorTargetRight)
    motorSpeedRight += rampStep;
  else if (motorSpeedRight > motorTargetRight)
    motorSpeedRight -= rampStep;

  ledcWrite(PIN_PWM_STICK_RY, motorSpeedRight);
}

void setupMotorTimer()
{
  // 1 MHz timer → 1 tick = 1 microsecond
  motorTimer = timerBegin(1000000);

  timerAttachInterrupt(motorTimer, &updateMotors);

  // Trigger interrupt every 20000 µs (20 ms)
  timerAlarm(motorTimer, 20000, true, 0);
}

void halSetCameraPan(uint32_t value) {
  ledcWrite(PIN_PWM_STICK_RY, value);
}

void halSetLed(uint32_t value) {
  ledcWrite(PIN_PWM_KNOB_L, value);
}

void halSetBuzzer(uint32_t value) {
  ledcWrite(PIN_PWM_KNOB_R, value);
}
/* ================= SET MOTOR DIRECTIONS ================= */
void setMotorLeftDirection(bool state){
  digitalWrite(PIN_MD_LEFT, state);
}

void setMotorRightDirection(bool state){
  digitalWrite(PIN_MD_RIGHT, state);
}


/* ================= SWITCHES ================= */

void halSetSwitch(uint8_t index, bool state) {

#if PROJECT_MODE == MODE_FULL_RC
  const uint8_t pins[4] = {
    PIN_SW1, PIN_SW2, PIN_SW3,
    PIN_SW4
  };

  if (index < 4)
    digitalWrite(pins[index], state);

#elif PROJECT_MODE == MODE_FULL_RC_MCP
  const uint8_t mcpPins[6] = {
    GPB0_SW1, GPB1_SW2, GPB2_SW3,
    GPB3_SW4, GPB4_SW5, GPB5_SW6
  };

  if (index < 6)
    mcpWriteOutput(mcpPins[index], state);
#endif
}

/* ================= PULSES ================= */

void halPulseSwitch(uint8_t index) {

#if PROJECT_MODE == MODE_FULL_RC
  const uint8_t gpioPulsePins[2] = { PIN_PULSE1, PIN_PULSE2 };

  if (index < 2)
    pulseStart(gpioPulsePins[index]);

#elif PROJECT_MODE == FULL_RC_MODE_MCP
  const uint8_t gpioPulsePins[4] = { PIN_PULSE1, PIN_PULSE2, PIN_PULSE3, PIN_PULSE4 };

  if (index < 4)
    pulseStart(gpioPulsePins[index]);
#endif
}
