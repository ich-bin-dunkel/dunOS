#include "idt.h"
#include "tui.h"
#include <stdint.h>

#define IDT_SIZE 256

typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_register_t;

idt_entry_t idt[IDT_SIZE];
idt_register_t idtr;

extern void idt_load(idt_register_t *idtr);

void idt_set_entry(int num, uint32_t base, uint16_t selector, uint8_t type_attr) {
    idt[num].offset_low = base & 0xFFFF;
    idt[num].selector = selector;
    idt[num].zero = 0;
    idt[num].type_attr = type_attr;
    idt[num].offset_high = (base >> 16) & 0xFFFF;
}

void idt_init() {
    idtr.limit = (sizeof(idt_entry_t) * IDT_SIZE) - 1;
    idtr.base = (uint32_t)&idt;

    // Initialize the IDT entries here
    // For example: idt_set_entry(32, (uint32_t)isr32, 0x08, 0x8E);

    idt_load(&idtr);
}

void isr_handler() {
    tui_print("Interrupt occurred!", 0, 0, WHITE_ON_BLACK);
}
