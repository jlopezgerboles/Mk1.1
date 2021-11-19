#include "logger_system.h"
#include "assertion_system.h"
#include "platform_system.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 LS_initialize() {
  return TRUE;
}

void LS_shutdown() {
}

void LS_output(log_level level, const char* message, ...) {
  const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]:  ", "[INFO]:  ", "[DEBUG]: ", "[TRACE]: "};
  b8 is_error = level < LOG_LEVEL_WARN;
  const i32 msg_length = 32000;
  char out_message[32000];
  memset(out_message, 0, sizeof(out_message));

  __builtin_va_list arg_ptr;
  va_start(arg_ptr, message);
  vsnprintf(out_message, msg_length, message, arg_ptr);
  va_end(arg_ptr);

  char out_message2[32000];
  sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

  if (is_error) {
    PS_console_write_error(out_message2, level);
  } else {
    PS_console_write(out_message2, level);
  }
}

void AS_failure(const char* expression, const char* message, const char* file, i32 line) {
  LS_output(LOG_LEVEL_FATAL, "Assertion failure: %s, message: '%s', in file %s, line: %d\n", expression, message, file, line);
}
