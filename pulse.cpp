#include "pulse.h"
#include "mcp_io.h"

/* =====================================================
   GPIO NON-BLOCKING PULSE
   ===================================================== */

struct PulseState {
  bool active;
  uint8_t pin;
  uint32_t startTime;
  uint16_t duration;
};

static PulseState gpioPulse = {false, 0, 0, 0};

void pulseStart(uint8_t pin, uint16_t durationMs) {

  if (gpioPulse.active) return;

  digitalWrite(pin, HIGH);

  gpioPulse.active = true;
  gpioPulse.pin = pin;
  gpioPulse.startTime = millis();
  gpioPulse.duration = durationMs;
}

void pulseUpdate() {

  if (!gpioPulse.active) return;

  if (millis() - gpioPulse.startTime >= gpioPulse.duration) {
    digitalWrite(gpioPulse.pin, LOW);
    gpioPulse.active = false;
  }
}