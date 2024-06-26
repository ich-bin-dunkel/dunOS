#include "tui.h"

void tui_init() {
    tui_clear();
}

void tui_clear() {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 2; i += 2) {
        VIDEO_MEMORY[i] = ' ';
        VIDEO_MEMORY[i + 1] = WHITE_ON_BLACK;
    }
}

void tui_print(const char *str, int row, int col, char color) {
    int offset = (row * SCREEN_WIDTH + col) * 2;
    while (*str) {
        VIDEO_MEMORY[offset++] = *str++;
        VIDEO_MEMORY[offset++] = color;
    }
}
