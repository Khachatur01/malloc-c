#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "allocation_table.h"

#define MEMORY_SIZE 1024
#define ALLOC_TABLE_SIZE 100
typedef int md_t; // memory descriptor type

uint8_t memory[MEMORY_SIZE];
used_memory_t allocation_table[ALLOC_TABLE_SIZE] = {0};

md_t alloc(int bytes) {
    int start = 0;
    int count = 0;

    for (int i = 0; i < ALLOC_TABLE_SIZE; i++) {
        bool is_used = is_index_used(allocation_table, ALLOC_TABLE_SIZE, i);
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

    int free_index = find_free_slot(allocation_table, ALLOC_TABLE_SIZE);
    allocation_table[free_index].start = start;
    allocation_table[free_index].count = count;
    allocation_table[free_index].in_use = true;

    printf("start = %d\n", start);
    printf("count = %d\n", count);

    return 0;
}

/*void free(md_t md) {
    allocation_table[md].in_use = false;
}*/

int main(void) {
    // used_memory_t allocation_table[10] = {0};
    // allocation_table[0].in_use = true;
    // allocation_table[1].in_use = true;
    // allocation_table[2].in_use = true;
    // allocation_table[4].in_use = true;
    //
    // int slot_index = find_free_slot(allocation_table, 10);
    // printf("%d\n", slot_index);
    //
    // used_memory_t allocation_table1[10] = {0};
    // allocation_table1[0].in_use = false;
    // allocation_table1[1].in_use = true;
    // allocation_table1[5].in_use = true;
    // allocation_table1[8].in_use = true;

    // int slot_index1 = find_free_slot(allocation_table1, 10);
    // printf("%d\n", slot_index1);

    alloc(10);
    alloc(3);
    alloc(12);

    // printf("%d\n", md1);
    //
    // md_t md22 = alloc(200);
    // printf("%d\n", md22);

    return 0;
}
