#ifndef FS_H
#define FS_H

void fs_init();
void fs_create_file(const char *filename);
void fs_write_file(const char *filename, const char *data);
char *fs_read_file(const char *filename);

#endif
