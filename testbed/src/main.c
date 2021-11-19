#include <logger_system.h>
#include <assertion_system.h>
#include <platform_system.h>

int main(void) {
  LS_FATAL("A test message: %f", 3.14f);
  LS_ERROR("A test message: %f", 3.14f);
  LS_WARN("A test message: %f", 3.14f);
  LS_INFO("A test message: %f", 3.14f);
  LS_DEBUG("A test message: %f", 3.14f);
  LS_TRACE("A test message: %f", 3.14f);

  platform_state state;
  if(PS_startup(&state, "Mk1 Phase 1 Test", 100, 100, 1280, 720)) {
    while(TRUE) {
      PS_pump_messages(&state);
    }
  };
  PS_shutdown(&state);
  return 0;
}
