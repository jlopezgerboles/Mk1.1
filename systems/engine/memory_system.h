#pragma once

#include "standards.h"

typedef enum memory_tags {
    MEMORY_TAG_STRING,
    MEMORY_TAG_KNOWN,
    MEMORY_TAG_MAX
} memory_tags_t;

void    MS_initialize();
void    MS_shutdown();
void*   MS_allocate(u64 memory_size, memory_tags_t memory_tag);
void    MS_free();
u64     MS_get_allocation_per_tag();
void*   MS_copy(void* destination, const void* source, u64 memory_size);