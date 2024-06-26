#include "fs.h"
#include "tui.h"
#include <string.h>

#define MAX_FILES 10
#define FILENAME_MAX_LENGTH 12
#define FILE_CONTENT_MAX_LENGTH 1024

typedef struct {
    char filename[FILENAME_MAX_LENGTH];
    char content[FILE_CONTENT_MAX_LENGTH];
} File;

File filesystem[MAX_FILES];

void fs_init() {
    for (int i = 0; i < MAX_FILES; i++) {
        filesystem[i].filename[0] = '\0';
    }
}

void fs_create_file(const char *filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (filesystem[i].filename[0] == '\0') {
            strncpy(filesystem[i].filename, filename, FILENAME_MAX_LENGTH);
            filesystem[i].content[0] = '\0';
            return;
        }
    }
}

void fs_write_file(const char *filename, const char *data) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strncmp(filesystem[i].filename, filename, FILENAME_MAX_LENGTH) == 0) {
            strncpy(filesystem[i].content, data, FILE_CONTENT_MAX_LENGTH);
            return;
        }
    }
}

char *fs_read_file(const char *filename) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strncmp(filesystem[i].filename, filename, FILENAME_MAX_LENGTH) == 0) {
            return filesystem[i].content;
        }
    }
    return NULL;
}
