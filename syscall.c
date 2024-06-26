#include "syscall.h"
#include "tui.h"

void syscall_init() {
    // Set up syscall handler in the IDT
    // For example: idt_set_entry(0x80, (uint32_t)syscall_handler, 0x08, 0x8E);
}

void syscall_handler() {
    // Handle the system call
    tui_print("System call executed!", 0, 0, WHITE_ON_BLACK);
}
