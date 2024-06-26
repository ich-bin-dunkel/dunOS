#include "tui.h"
#include "terminal.h"
#include "fs.h"
#include "idt.h"
#include "paging.h"
#include "syscall.h"

void main() {
    tui_init();
    idt_init();
    paging_init();
    syscall_init();
    fs_init();
    terminal_init();
    terminal_loop();
}
