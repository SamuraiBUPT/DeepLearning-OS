#include "port.h"

Port::Port(uint16_t portNumber)
{
    this->portNumber = portNumber;
}

Port::~Port()
{
}

// 8-bit port
Port_8bit::Port_8bit(uint16_t portNumber) : Port(portNumber){};

void Port_8bit::Write(uint8_t data)
{
    __asm__ volatile("outb %0, %1"
                     :
                     : "a"(data), "Nd"(portNumber));
}

uint8_t Port_8bit::Read()
{
    uint8_t result;
    __asm__ volatile("inb %1, %0"
                     : "=a"(result)
                     : "Nd"(portNumber));
    return result;
}

Port_8bit::~Port_8bit(){};

// 8-bit port SLOW
Port_8bitSlow::Port_8bitSlow(uint16_t portNumber) : Port_8bit(portNumber){};

void Port_8bitSlow::Write(uint8_t data)
{
    __asm__ volatile("outb %0, %1\njmp 1f\n1: jmp 1f\n1:"
                     :
                     : "a"(data), "Nd"(portNumber));
}

Port_8bitSlow::~Port_8bitSlow(){};

// 16-bit port
Port_16bit::Port_16bit(uint16_t portNumber) : Port(portNumber){};

void Port_16bit::Write(uint16_t data)
{
    __asm__ volatile("outw %0, %1"
                     :
                     : "a"(data), "Nd"(portNumber));
}

uint16_t Port_16bit::Read()
{
    uint16_t result;
    __asm__ volatile("inw %1, %0"
                     : "=a"(result)
                     : "Nd"(portNumber));
    return result;
}

Port_16bit::~Port_16bit(){};

// 32-bit port
Port_32bit::Port_32bit(uint16_t portNumber) : Port(portNumber){};

void Port_32bit::Write(uint32_t data)
{
    __asm__ volatile("outl %0, %1"
                     :
                     : "a"(data), "Nd"(portNumber));
}

uint32_t Port_32bit::Read()
{
    uint32_t result;
    __asm__ volatile("inl %1, %0"
                     : "=a"(result)
                     : "Nd"(portNumber));
    return result;
}

Port_32bit::~Port_32bit(){};