#ifndef MALLOC_ALLOCATION_TABLE_H
#define MALLOC_ALLOCATION_TABLE_H
#include <stdbool.h>

typedef struct {
    int start;
    int count;
    bool in_use;  // false -> 0, true -> 1
} used_memory_t;

int find_free_slot(used_memory_t* table, int size);
bool is_index_used(used_memory_t* table, int size, int index);

#endif //MALLOC_ALLOCATION_TABLE_H