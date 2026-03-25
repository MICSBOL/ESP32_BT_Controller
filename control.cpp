/*
  control.cpp
  ------------------------------------------------------
  CONTROL LAYER – Hardware Output Logic
*/

#include <Arduino.h>
#include "control.h"
#include "packets.h"
#include "hal_outputs.h"

/* =====================================================
   INTERNAL HELPERS
   ===================================================== */

static uint32_t mapServo(uint16_t v) {
  return map(v, 0, 4095, 205, 410);
}

/* =====================================================
   MAIN CONTROL UPDATE
   ===================================================== */

void controlUpdate() {

  uint32_t steerPWM = mapServo(rcStatePacket.data.leftStickX);
  uint32_t panPWM   = mapServo(rcStatePacket.data.rightStickX);
  uint32_t motorL   = rcStatePacket.data.leftStickY;
  uint32_t motorR   = rcStatePacket.data.rightStickY;


  halSetSteering(steerPWM);
  halSetMotorLeft(motorL);
  halSetMotorRight(motorR);
  halSetCameraPan(panPWM);


  halSetLed(rcStatePacket.data.leftKnob);
  halSetBuzzer(rcStatePacket.data.rightKnob);

  byte sw = rcStatePacket.data.switches;

  for (int i = 0; i < 6; i++) {
    halSetSwitch(i, (sw >> i) & 1);
  }
}



/* =====================================================
   EVENT HANDLING
   ===================================================== */

void controlHandleEvent(byte eventId) {

#if PROJECT_MODE == FULL_RC_MODE

  switch (eventId) {
    case 0x01: halPulseSwitch(0); break;
    case 0x02: halPulseSwitch(1); break;
    case 0x03: halPulseSwitch(0); break;
    case 0x04: halPulseSwitch(1); break;
    default: break;
  }

#elif PROJECT_MODE == FULL_RC_MODE_MCP
  switch (eventId) {
    case 0x01: halPulseSwitch(0); break;
    case 0x02: halPulseSwitch(1); break;
    case 0x03: halPulseSwitch(2); break;
    case 0x04: halPulseSwitch(3); break;
    default: break;
  }
#endif
}
