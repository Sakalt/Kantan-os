#include "physical_memory.h"
#include <stdbool.h>

static bool frame_bitmap[TOTAL_FRAMES]; // フレームの空き状況をビットマップで管理

// 物理メモリの初期化
void init_physical_memory() {
    for (size_t i = 0; i < TOTAL_FRAMES; i++) {
        frame_bitmap[i] = false; // 全フレームを未使用に設定
    }
}

// フレームの割り当て
void* alloc_frame() {
    for (size_t i = 0; i < TOTAL_FRAMES; i++) {
        if (!frame_bitmap[i]) { // 未使用フレームを探す
            frame_bitmap[i] = true;
            return (void*)(i * FRAME_SIZE); // フレームのアドレスを返す
        }
    }
    return NULL; // 空きフレームがない
}

// フレームの解放
void free_frame(void* frame) {
    size_t index = (size_t)frame / FRAME_SIZE;
    if (index < TOTAL_FRAMES) {
        frame_bitmap[index] = false; // フレームを解放
    }
}
