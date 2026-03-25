#include <Arduino.h>
#include <Wire.h>
#include "pins.h"
#include "board_init.h"
#include "hal_outputs.h"

void halOutputsInit()
{
  setupMotorTimer();
}

/* ================= FULL RC ================= */

static void initFullRC() {

  /* ================= I2C ================= */
  Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);

  /* ================= SWITCH OUTPUTS ================= */
  pinMode(PIN_SW1, OUTPUT);
  pinMode(PIN_SW2, OUTPUT);
  pinMode(PIN_SW3, OUTPUT);
  pinMode(PIN_SW4, OUTPUT);

    /* ================= MOTORS DIRECTIONS OUTPUTS ================= */
  pinMode(PIN_MD_LEFT, OUTPUT);
  pinMode(PIN_MD_RIGHT, OUTPUT);

  // Ensure boot-sensitive pins start LOW
  digitalWrite(PIN_MD_LEFT, LOW);  // GPIO12
  digitalWrite(PIN_MD_RIGHT, LOW);  // GPIO15

  /* ================= PWM OUTPUTS (6) ================= */

  const uint32_t pwmFreq = 20000;
  const uint8_t  pwmRes  = 12;

  ledcAttach(PIN_PWM_STICK_LX, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_STICK_LY, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_STICK_RX, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_STICK_RY, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_KNOB_L,   pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_KNOB_R,   pwmFreq, pwmRes);

  // Initialize PWM to 0 duty
  ledcWrite(PIN_PWM_STICK_LX, 0);
  ledcWrite(PIN_PWM_STICK_LY, 0);
  ledcWrite(PIN_PWM_STICK_RX, 0);
  ledcWrite(PIN_PWM_STICK_RY, 0);
  ledcWrite(PIN_PWM_KNOB_L,   0);
  ledcWrite(PIN_PWM_KNOB_R,   0);

  /* ================= DIGITAL INPUTS (4) ================= */

  pinMode(PIN_IND1, INPUT);
  pinMode(PIN_IND2, INPUT);
  pinMode(PIN_IND3, INPUT);
  pinMode(PIN_IND4, INPUT);

  // IMPORTANT:
  // GPIO0 and GPIO2 are boot-sensitive.
  // Do NOT enable INPUT_PULLUP here.

  /* ================= ANALOG INPUTS (ADC1) ================= */

  analogReadResolution(12);        // 0–4095
  analogSetAttenuation(ADC_11db);  // Recommended for full 0–3.3V range

  pinMode(PIN_NUMERIC1,    INPUT);
  pinMode(PIN_NUMERIC2,    INPUT);
  pinMode(PIN_ANALOG_IND1, INPUT);
  pinMode(PIN_ANALOG_IND2, INPUT);

  
  /* ================= DIGITAL OUTPUTS (2) ================ */
  pinMode(PIN_PULSE1, OUTPUT);
  pinMode(PIN_PULSE2, OUTPUT);
  
  
}

/* ================= FULL RC MCP ================= */

static void initFullRCMcp() {

  /* =====================================================
     NOTE:
     - I2C is initialized in i2cBusInit()
     - MCP23017 is initialized in mcpInit()
     ===================================================== */

  /* ================= PWM OUTPUTS (6) ================= */

  const uint32_t pwmFreq = 20000;
  const uint8_t  pwmRes  = 12;

  ledcAttach(PIN_PWM_STICK_LX, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_STICK_LY, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_STICK_RX, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_STICK_RY, pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_KNOB_L,   pwmFreq, pwmRes);
  ledcAttach(PIN_PWM_KNOB_R,   pwmFreq, pwmRes);

  // Initialize all PWM outputs to 0 duty
  ledcWrite(PIN_PWM_STICK_LX, 0);
  ledcWrite(PIN_PWM_STICK_LY, 0);
  ledcWrite(PIN_PWM_STICK_RX, 0);
  ledcWrite(PIN_PWM_STICK_RY, 0);
  ledcWrite(PIN_PWM_KNOB_L,   0);
  ledcWrite(PIN_PWM_KNOB_R,   0);

  /* ================= ANALOG INPUTS (ADC1 ONLY) ================= */

  analogReadResolution(12);        // 0–4095
  analogSetAttenuation(ADC_11db);  // 0–3.3V range

  pinMode(PIN_NUMERIC1,     INPUT);
  pinMode(PIN_NUMERIC2,     INPUT);
  pinMode(PIN_ANALOG_IND1,  INPUT);
  pinMode(PIN_ANALOG_IND2,  INPUT);

  /* ================= FREE GPIO (optional use) ================= */

  pinMode(PIN_PULSE1, OUTPUT);
  pinMode(PIN_PULSE2, OUTPUT);
  pinMode(PIN_PULSE3, OUTPUT);
  pinMode(PIN_PULSE4, OUTPUT);
  pinMode(PIN_FREE5, OUTPUT);
  pinMode(PIN_FREE6, OUTPUT);

  digitalWrite(PIN_PULSE1, LOW);
  digitalWrite(PIN_PULSE2, LOW);
  digitalWrite(PIN_PULSE3, LOW);
  digitalWrite(PIN_PULSE4, LOW);
  digitalWrite(PIN_FREE5, LOW);
  digitalWrite(PIN_FREE6, LOW);
}



/* ================= PUBLIC ================= */

void boardInit() {

#if PROJECT_MODE == FULL_RC_MODE
  initFullRC();
#elif PROJECT_MODE == FULL_RC_MODE_MCP
  initFullRCMcp();
#endif
}
