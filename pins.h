#ifndef PINS_H
#define PINS_H

#if PROJECT_MODE == FULL_RC_MODE

/* =====================================================
   I2C BUS (reserved)
   ===================================================== */
#define PIN_I2C_SDA 21
#define PIN_I2C_SCL 22


/* =====================================================
   PWM OUTPUTS (6 total)
   ===================================================== */
#define PIN_PWM_STICK_LX 18
#define PIN_PWM_STICK_LY 19
#define PIN_PWM_STICK_RX 23
#define PIN_PWM_STICK_RY 25
#define PIN_PWM_KNOB_L   26   //
#define PIN_PWM_KNOB_R   27   //


/* =====================================================
   SWITCH OUTPUTS (6)
   ===================================================== */
#define PIN_SW1 16   
#define PIN_SW2 17
#define PIN_SW3 13
#define PIN_SW4 14

/* =====================================================
   MOTORS DIRECTION OUTPUTS (2)
   ===================================================== */
#define PIN_MD_LEFT 12   // keep LOW at boot
#define PIN_MD_RIGHT 15   // keep LOW at boot


/* =====================================================
   ANALOG INPUTS (ADC1 ONLY — SAFE WITH BT)
   ===================================================== */
#define PIN_NUMERIC1      34
#define PIN_NUMERIC2      35
#define PIN_ANALOG_IND1   36
#define PIN_ANALOG_IND2   39


/* =====================================================
   DIGITAL INPUTS (4 indicators instead of 8)
   ===================================================== */
#define PIN_IND1 4
#define PIN_IND2 5
#define PIN_IND3 2
#define PIN_IND4 0   // careful: avoid pull-up at boot

/* =====================================================
   PULSE OUTPUTS (Android buttons)
   ===================================================== */
#define PIN_PULSE1 32
#define PIN_PULSE2 33


#endif
/* ========================================================================================================== */

#if PROJECT_MODE == FULL_RC_MODE_MCP

/* =====================================================
   I2C BUS (ESP32 <-> MCP23017)
   ===================================================== */
#define PIN_I2C_SDA 21
#define PIN_I2C_SCL 22

/* =====================================================
   PWM OUTPUTS (6 total - direct from ESP32)
   ===================================================== */
#define PIN_PWM_STICK_LX 18
#define PIN_PWM_STICK_LY 19
#define PIN_PWM_STICK_RX 23
#define PIN_PWM_STICK_RY 25
#define PIN_PWM_KNOB_L   26
#define PIN_PWM_KNOB_R   27

/* =====================================================
   ANALOG INPUTS (ADC1 SAFE WITH BT)
   ===================================================== */
#define PIN_NUMERIC1      32
#define PIN_NUMERIC2      33
#define PIN_ANALOG_IND1   34
#define PIN_ANALOG_IND2   35

/* =====================================================
   MOTORS DIRECTION OUTPUTS (2)
   ===================================================== */
#define PIN_MD_LEFT 12   // keep LOW at boot
#define PIN_MD_RIGHT 15   // keep LOW at boot


/* =====================================================
   BUTTONS PULSE OUTPUTS (4)
   ===================================================== */
#define PIN_PULSE1 4
#define PIN_PULSE2 5
#define PIN_PULSE3 13
#define PIN_PULSE4 14

/* =====================================================
   FREE I/O OUTPUTS (2)
   ===================================================== */
#define PIN_FREE5 16
#define PIN_FREE6 17

/* =====================================================
   MCP23017 DIGITAL ASSIGNMENTS
   ===================================================== */

/*
   GPA0–GPA7  → 8 Digital Indicators (INPUTS)
   GPB0–GPB5  → 6 Switch Outputs
*/

#define GPA0   0
#define GPA1   1
#define GPA2   2
#define GPA3   3
#define GPA4   4
#define GPA5   5
#define GPA6   6
#define GPA7   7

#define GPB0_SW1   0
#define GPB1_SW2   1
#define GPB2_SW3   2
#define GPB3_SW4   3
#define GPB4_SW5   4
#define GPB5_SW6   5
#define GPB6   6
#define GPB7   7


#define MCP_ADDR 0x20
#endif

#endif