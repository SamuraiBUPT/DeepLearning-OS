#include "types.h"
#include "gdt.h"

void printf(const char *str)
{
    static uint16_t *VideoMemory = (uint16_t *)0xb8000;
    static uint8_t x = 0, y = 0; // set a cursor

    for (int i = 0; str[i] != '\0'; ++i)
    {
        switch (str[i])
        {
        case '\n':
            y++;
            x = 0;
            break;

        default:
            VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0xFF00) | str[i];
            x++;
        }

        if (x >= 80)
        {
            y++;
            x = 0;
        }
        if (y >= 25)
        {
            // clear the whole screen
            for (y = 0; y < 25; y++)
            {
                for (x = 0; x < 80; x++)
                {
                    VideoMemory[80 * y + x] = (VideoMemory[80 * y + x] & 0xFF00) | ' ';
                }
            }

            // reset the number
            x = 0;
            y = 0;
        }
    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;

extern "C" void callConstructors()
{
    for (constructor *i = &start_ctors; i != &end_ctors; i++)
    {
        (*i)();
    }
}

extern "C" void kernelMain(void *multiboot_structure, uint32_t magicnumber)
{
    printf((char *)"This is your own operating system demo.\n");
    printf((char *)"=======================================\n");
    printf((char *)"\n");
    printf((char *)"Author: Conqueror712, Samurai_BUPT.\n");
    printf((char *)"Create Time: 02-27, 2023\n");
    printf((char *)"\n");
    printf((char *)"=======================================\n");
    printf((char *)"\n");
    printf((char *)"It features the 90's computer style, including font, GUI, browser etc..\n");
    printf((char *)"Join us, and let us reshape the world.");
    printf((char *)"\n");
    printf((char *)"=======================================\n");

    GlobalDescriptorTable gdt;
    while (1)
        ;
}