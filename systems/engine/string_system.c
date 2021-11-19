#include "string_system.h"
#include "memory_system.h"

u64 SS_length(const char* string) {
    u64 length = strlen(string);
    return length;
}

char* SS_duplicate(const char* string) {
    u64 length = SS_length(string);
    char* copy = MS_allocate(length + 1, MEMORY_TAG_STRING);
    MS_copy(copy, string, length + 1);
    return copy;
}

b8 SS_compare(const char* string_0, const char* string_1) {
    return strcmp(string_0, string_1) == 0;
}