#pragma once

#include "standards.h"

typedef struct platform_state {
  void* internal_state;
} platform_state;

EXP b8 PS_startup(platform_state *plat_state, const char *application_name, i32 x, i32 y, i32 width, i32 height);
EXP void PS_shutdown(platform_state *plat_state);
EXP b8 PS_pump_messages(platform_state *plat_state);

void*     PS_allocate_memory(u64 size, b8 aligned);
void      PS_free_memory(void* block, b8 aligned);
void*     PS_zero_memory(void* block, u64 size);
void*     PS_copy_memory(void* dest, const void* source, u64 size);
void*     PS_set_memory(void* dest, i32 value, u64 size);
void      PS_console_write(const char* message, u8 colour);
void      PS_console_write_error(const char* message, u8 colour);
f64       PS_get_absolute_time();
void      PS_sleep(u64 ms);
