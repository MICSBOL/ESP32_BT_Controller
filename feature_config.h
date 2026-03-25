#ifndef FEATURE_CONFIG_H
#define FEATURE_CONFIG_H

/* ==============================
   TELEMETRY MODULES
   ============================== */
#if PROJECT_MODE == FULL_RC_MODE

  #undef USE_PWM_OUTPUTS
  #undef USE_SWITCH_OUTPUTS
  #undef USE_EVENT_OUTPUTS

  #define USE_PWM_OUTPUTS        1
  #define USE_SWITCH_OUTPUTS     1
  #define USE_EVENT_OUTPUTS      1
  #define USE_TELEMETRY          0
  #define USE_I2C_SENSOR         0

#elif PROJECT_MODE == FULL_RC_MODE_MCP

  #undef USE_PWM_OUTPUTS
  #undef USE_SWITCH_OUTPUTS
  #undef USE_EVENT_OUTPUTS

  #define USE_PWM_OUTPUTS        1
  #define USE_SWITCH_OUTPUTS     1
  #define USE_EVENT_OUTPUTS      1
  #define USE_TELEMETRY          0
  #define USE_I2C_SENSOR         0

#endif

/* ==============================
   DEBUG MODE
   ============================== */

#define ENABLE_DEBUG             1

#endif