
#include "include/types.h"
#include "include/gdt.h"

const uint8_t SCREEN_HEIGHT = 25, SCREEN_WIDTH = 80;

void printf(char* str)
{
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    static uint8_t cur_x = 0, cur_y = 0;

    for(int i = 0; str[i] != '\0'; ++i)
    {

    	switch (str[i]) {
    		case '\n':
    			cur_y++;
    			cur_x = 0;
    			break;

    		default:
		        VideoMemory[SCREEN_WIDTH * cur_y + cur_x] = (VideoMemory[SCREEN_WIDTH * cur_y + cur_x] & 0xFF00) | str[i];
		        cur_x++;
		        break;
		}

        if (cur_x >= SCREEN_WIDTH) {
        	cur_y++;
        	cur_x = 0;
        }

        if (cur_y >= SCREEN_HEIGHT) {
        	for (cur_y = 0; cur_y < SCREEN_HEIGHT; cur_y++) {
        		for (cur_x = 0; cur_x < SCREEN_WIDTH; cur_x++) {
        			VideoMemory[SCREEN_WIDTH * cur_y + cur_x] = (VideoMemory[SCREEN_WIDTH * cur_y + cur_x] & 0xFF00) | ' ';
        		}
        	}

        	cur_x = 0;
        	cur_y = 0;
        }
    }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors; i != &end_ctors; i++)
        (*i)();
}


extern "C" void kernelMain(const void* multiboot_structure, uint32_t /*multiboot_magic*/)
{
    printf("Successfully booted.");

    GlobalDescriptorTable gdt;

    while(1);
}
