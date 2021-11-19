#pragma once

#include "standards.h"

// Disable assertions by commenting out the below line.
#define ASSERTIONS_ENABLED

#ifdef ASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

EXP void AS_report_failure(const char* expression, const char* message, const char* file, i32 line);

#define ASSERT(expr)                                          \
    {                                                         \
        if (expr) {                                           \
        } else {                                              \
            AS_report_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                     \
        }                                                     \
    }

#define ASSERT_MSG(expr, message)                                   \
    {                                                               \
        if (expr) {                                                 \
        } else {                                                    \
            AS_report_failure(#expr, message, __FILE__, __LINE__);  \
            debugBreak();                                           \
        }                                                           \
    }

#ifdef _DEBUG
#define ASSERT_DEBUG(expr)                                    \
    {                                                         \
        if (expr) {                                           \
        } else {                                              \
            AS_report_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                     \
        }                                                     \
    }
#else
#define ASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define ASSERT(expr)               // Does nothing at all
#define ASSERT_MSG(expr, message)  // Does nothing at all
#define ASSERT_DEBUG(expr)         // Does nothing at all
#endif