#include "paging.h"
#include "tui.h"
#include <stdint.h>

#define PAGE_SIZE 4096
#define KERNEL_START_ADDR 0x100000

extern void load_page_directory(uint32_t *);
extern void enable_paging();

uint32_t page_directory[1024] __attribute__((aligned(PAGE_SIZE)));
uint32_t first_page_table[1024] __attribute__((aligned(PAGE_SIZE)));

void paging_init() {
    for (int i = 0; i < 1024; i++) {
        page_directory[i] = 0x00000002;
        first_page_table[i] = (i * PAGE_SIZE) | 3;
    }
    page_directory[0] = ((uint32_t)first_page_table) | 3;

    load_page_directory(page_directory);
    enable_paging();
}
