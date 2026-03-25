#include "system_init.h"
#include "pulse.h"

void setup() {
  systemInit();
}

void loop() {
  systemLoop();
  pulseUpdate();

#if USE_MCP23017
  mcpPulseUpdate();
#endif
}
