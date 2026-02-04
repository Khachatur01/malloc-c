#ifndef MALLOC_ALLOCATION_TABLE_H
#define MALLOC_ALLOCATION_TABLE_H
#include <stdbool.h>
#include <stdint.h>

#define MEMORY_SIZE 1024
#define ALLOC_TABLE_SIZE 200

typedef int md_t; // memory descriptor type

typedef struct {
    int start;
    int count;
    bool in_use;  // false -> 0, true -> 1
} used_memory_t;

typedef struct {
    uint8_t memory[MEMORY_SIZE];
    used_memory_t table[ALLOC_TABLE_SIZE];
} allocator_t;

void allocator_init(allocator_t* allocator);
md_t c_malloc(allocator_t* allocator, int bytes);
void c_free(allocator_t* allocator, md_t md);

int find_free_slot(allocator_t* allocator);
bool is_index_used(allocator_t* allocator, int index);

#endif //MALLOC_ALLOCATION_TABLE_H