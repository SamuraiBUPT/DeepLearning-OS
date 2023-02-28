/*
    'gdt' stands for 'Global Descriptor Table', which aims to interrupt.

    Author: Samurai
    Time: 2023-02-27
*/

#ifndef __GDT_H
#define __GDT_H

#include "types.h"

class GlobalDescriptorTable
{
public:
    class SegmentDescriptor
    {
    private:
        uint16_t limit_l;      // Limit Byte_LOW 2 Bytes: 0-15
        uint16_t base_l;       // Base Byte_LOW 2 Bytes: 16-31
        uint8_t base_h;        // Base Byte_HIGH Byte: 32-39
        uint8_t type;          // Access Rights Byte: 40-47
        uint8_t flags_limit_h; // Flags & Limit Byte: 48-55
        uint8_t base_vhi;      //  left: Base pointer: 56-63

    public:
        SegmentDescriptor(uint32_t base, uint32_t limit, uint8_t flags);
        uint32_t Base();
        uint32_t Limit();
    } __attribute__((packed));

    SegmentDescriptor nullSegmentSelector;
    SegmentDescriptor unusedSegmentSelector;
    SegmentDescriptor codeSegmentSelector;
    SegmentDescriptor dataSegmentSelector;

public:
    GlobalDescriptorTable();
    ~GlobalDescriptorTable();

    uint16_t CodeSegmentSelector(); // returns the offset of the 'code segment descriptor'
    uint16_t DataSegmentSelector(); // returns the offset of the 'data segment descriptor'
};

#endif