#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "allocation_table.h"

allocator_t allocator;

int main(void) {
    allocator_init(&allocator);
    md_t md1 = c_malloc(&allocator, 10);
    md_t md2 = c_malloc(&allocator, 25);
    md_t md3 = c_malloc(&allocator, 25);
    printf("%d, %d, %d", md1, md2, md3);
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

    printf("alloc 1\n");
    // md_t md1 = alloc(10);
    // printf("\nalloc 2\n");
    // md_t md2 = alloc(10);
    // free_memory_slot(allocation_table,ALLOC_TABLE_SIZE,md1);
    // printf("\nalloc 3\n");
    // alloc(3);
    // printf("\nalloc 4\n");
    // alloc(12);
    // printf("\nalloc 5\n");
    // alloc(20);

    return 0;
}
