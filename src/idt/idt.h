#ifndef IDT_H
#define IDT_H

#include <stdint.h>

struct idt_desc
{
    uint16_t offset_1;  // Offset bits 0-15
    uint16_t selector;  // selector in GDT
    uint8_t zero;
    uint8_t type_attr;  // descriptor type
    uint16_t offset_2; // offset 16-31
} __attribute__((packed));

struct idtr_desc
{
    uint16_t limit; // size of desc table - 1
    uint32_t base;  // base addr of the start of table
} __attribute__((packed));

void idt_init();

#endif