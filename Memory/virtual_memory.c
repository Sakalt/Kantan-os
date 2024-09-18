#include "virtual_memory.h"
#include "physical_memory.h"

#define PAGE_SIZE 4096 // 4KBページ
#define TOTAL_PAGES 64 // 仮想メモリ内のページ数（256KB ÷ 4KB = 64ページ）

static void* page_table[TOTAL_PAGES]; // 仮想アドレスから物理アドレスへのマッピング

// 仮想メモリの初期化
void init_virtual_memory() {
    for (size_t i = 0; i < TOTAL_PAGES; i++) {
        page_table[i] = NULL; // すべてのページを未マッピングに設定
    }
}

// 仮想アドレスを物理アドレスにマッピング
void map_page(void* virtual_address, void* physical_address) {
    size_t index = (size_t)virtual_address / PAGE_SIZE;
    if (index < TOTAL_PAGES) {
        page_table[index] = physical_address;
    }
}

// 仮想アドレスに対応する物理アドレスを取得
void* get_physical_address(void* virtual_address) {
    size_t index = (size_t)virtual_address / PAGE_SIZE;
    if (index < TOTAL_PAGES) {
        return page_table[index];
    }
    return NULL;
}
