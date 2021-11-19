#include "standards.h"
#include "memory_system.h"
#include "platform_system.h"

typedef struct MS_stats_s {
    u64 memory_allocated;
    u64 memory_assigned_per_tag[MEMORY_TAG_MAX];
} MS_stats_t;

typedef struct MS_state_s {
    MS_stats_t memory_stats;
    u64 memory_allocate_count;
} MS_state_t;

static MS_state_t* memory_state_pointer;

void MS_initialize(u64* memory_requirement, void* state) {
    *memory_requirement = sizeof(MS_state_t);
    if(state == 0) return;
    memory_state_pointer = state;
    memory_state_pointer -> memory_allocate_count = 0;
    PS_zero_memory(&memory_state_pointer -> memory_stats, sizeof(memory_state_pointer -> memory_stats));
}

void MS_shutdown(void* state) {
    memory_state_pointer = 0;
}

void MS_allocate(u64 memory_size, memory_tags_t memory_tag) {
    if(memory_tag == 0) return;
    if(memory_state_pointer) {
        memory_state_pointer -> memory_stats.memory_allocated += memory_size;
        memory_state_pointer -> memory_stats.memory_assigned_per_tag[memory_tag] += memory_size;
        memory_state_pointer -> memory_allocate_count ++;
    };
    void* block = PS_allocate_memory(memory_size, FALSE);
    PS_zero_memory(block, memory_size);
    return *block;
}

void MS_free(void* block, u64 memory_size, memory_tags_t memory_tag) {
    if(memory_tag == 0) return;
    if(memory_state_pointer) {
        memory_state_pointer -> memory_stats.memory_allocated -= memory_size;
        memory_state_pointer -> memory_stats.memory_assigned_per_tag[memory_tag] -= memory_size;
        memory_state_pointer -> memory_allocate_count --;
        PS_free_memory(block, FALSE);
    }
}

u64 MS_get_memory_allocation_count() {
    if(!memory_state_pointer) return 0;
    return memory_state_pointer -> memory_allocate_count;
}