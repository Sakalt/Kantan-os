#ifndef VIRTUAL_MEMORY_H
#define VIRTUAL_MEMORY_H

#include <stddef.h>

void init_virtual_memory();
void map_page(void* virtual_address, void* physical_address);
void* get_physical_address(void* virtual_address);

#endif
