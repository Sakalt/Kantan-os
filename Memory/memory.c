#include "physical_memory.h"
#include "virtual_memory.h"
#include "heap.h"

// メモリ管理システム全体の初期化
void init_memory_system() {
    init_physical_memory();
    init_virtual_memory();
    // 他のメモリ関連の初期化もここで行うことができる
}
