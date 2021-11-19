#pragma once

#include "standards.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Disable debug and trace logging for release builds.
#if RELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;

b8          LS_initialize(u64* memory_requirement, void* state);
void        LS_shutdown(void* state);
EXP void    LS_output(log_level level, const char* message, ...);

#define LS_FATAL(message, ...) LS_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef LS_ERROR
#define LS_ERROR(message, ...) LS_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
#define LS_WARN(message, ...) LS_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define LS_WARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
#define LS_INFO(message, ...) LS_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define LS_INFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
#define LS_DEBUG(message, ...) LS_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define LS_DEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
#define LS_TRACE(message, ...) LS_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define LS_TRACE(message, ...)
#endif
