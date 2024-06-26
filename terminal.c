#include "tui.h"
#include "terminal.h"
#include "fs.h"
#include <string.h>

void terminal_init() {
    tui_clear();
    tui_print("Terminal", 0, 0, WHITE_ON_BLACK);
}

void terminal_loop() {
    char command[SCREEN_WIDTH];
    int cursor_col = 0;
    char key;

    while (1) {
        key = get_key();
        if (key == '\n') {
            command[cursor_col] = '\0';
            cursor_col = 0;

            if (strncmp(command, "editor", 6) == 0) {
                editor_init();
                editor_loop();
            } else if (strncmp(command, "pong", 4) == 0) {
                pong_init();
                pong_loop();
            } else {
                tui_print("Unknown command", 2, 0, WHITE_ON_BLACK);
            }
            tui_clear();
            tui_print("Terminal", 0, 0, WHITE_ON_BLACK);
        } else if (key == '\b') {
            if (cursor_col > 0) {
                cursor_col--;
                command[cursor_col] = ' ';
            }
        } else {
            command[cursor_col++] = key;
        }
        tui_print(command, 1, 0, WHITE_ON_BLACK);
    }
}
