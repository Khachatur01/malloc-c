#include "allocation_table.h"

int find_free_slot(used_memory_t* table, int size) {
    for (int i = 0; i < size; i++) {
        if (table[i].in_use == false)
            return i;
    }
    return -1;
}

bool check_index (used_memory_t* table, int size, int index) {
    return false;
}
