#ifndef PHYSICAL_MEMORY_H
#define PHYSICAL_MEMORY_H

#include <stddef.h>

#define FRAME_SIZE 4096   // 1フレーム = 4KB
#define TOTAL_FRAMES 64   // 256KB / 4KB = 64フレーム

void init_physical_memory();
void* alloc_frame();
void free_frame(void* frame);

#endif
