#pragma once

#include "standards.h"
#include "memory_system.h"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

EXP u64     SS_length(const char* string);
EXP char*   SS_duplicate(const char* string);
EXP b8      SS_compare(const char* string_0, const char* string_1);