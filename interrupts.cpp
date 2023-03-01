#include "interrupts.h"

void printf(char *str){};

// 实现的时候不需要加上static，因为这是声明型关键字
uint32_t interruptManager::handleInterrupt(uint8_t interruptNumber, uint32_t esp)
{
    printf((char *)"INTERRUPT");
    return esp;
}