#ifndef TUI_H
#define TUI_H

#define VIDEO_MEMORY (char *)0xb8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define WHITE_ON_BLACK 0x07

void tui_init();
void tui_clear();
void tui_print(const char *str, int row, int col, char color);

#endif
