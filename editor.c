#include "editor.h"
#include "tui.h"
#include "fs.h"
#include <string.h>

#define MAX_FILE_LENGTH 1024

char current_filename[FILENAME_MAX_LENGTH];
char editor_buffer[MAX_FILE_LENGTH];

void editor_init() {
    tui_clear();
    tui_print("Text Editor - Enter filename: ", 0, 0, WHITE_ON_BLACK);
    current_filename[0] = '\0';
}

void editor_loop() {
    int cursor_pos = 0;
    char key;

    while (1) {
        key = get_key();
        if (key == '\n') {
            if (current_filename[0] != '\0') {
                fs_write_file(current_filename, editor_buffer);
                tui_print("File saved.", 1, 0, WHITE_ON_BLACK);
                break;
            }
        } else if (key == '\b') {
            if (cursor_pos > 0) {
                cursor_pos--;
                editor_buffer[cursor_pos] = ' ';
            }
        } else {
            editor_buffer[cursor_pos++] = key;
        }
        editor_buffer[cursor_pos] = '\0';
        tui_print(editor_buffer, 1, 0, WHITE_ON_BLACK);
    }
}
