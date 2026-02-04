#include "allocation_table.h"

void allocator_init(allocator_t* allocator){
    for (int i = 0; i < ALLOC_TABLE_SIZE; i++) {
        allocator->table[i].in_use = false;
    }
}

md_t c_malloc(allocator_t* allocator, int bytes) {
    int start = 0;
    int count = 0;

    for (int i = 0; i < ALLOC_TABLE_SIZE; i++) {
        bool is_used = is_index_used(allocator, i);
        if (is_used) {
            count = 0;
            continue;
        }

        if (count == 0) {
            start = i;
        }

        count++;

        if (count == bytes) {
            break;
        }
    }

    int free_index = find_free_slot(allocator);
    allocator->table[free_index].start = start;
    allocator->table[free_index].count = count;
    allocator->table[free_index].in_use = true;

    // printf("start = %d\n", start);
    // printf("count = %d\n", count);
    // printf("end = %d\n", start + count);

    return free_index;
}

void c_free(allocator_t* allocator, md_t md){

    if(allocator->table[md].in_use)
        allocator->table[md].in_use = 0;    
}

int find_free_slot(allocator_t* allocator) {
    for (int i = 0; i < ALLOC_TABLE_SIZE; i++) {
        if (allocator->table[i].in_use == false)
            return i;
    }
    return -1;
}

bool is_index_used(allocator_t* allocator, int index) {

    for (int i = 0; i < ALLOC_TABLE_SIZE; i++) {
        if (allocator->table[i].in_use == false) {
            continue;
        }

        if( index >= allocator->table[i].start && index < (allocator->table[i].start + allocator->table[i].count))
            return true;

    }
    return false;
}