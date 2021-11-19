#pragma once

typedef enum memory_tags {
    MEMORY_TAG_UNKNOWN,
    MEMORY_TAG_KNOWN,
    MEMORY_TAG_MAX
} memory_tags_t;

void MS_initialize();
void MS_shutdown();
void MS_allocate();
void MS_free();
u64 MS_get_allocation_per_tag();