#include "system.h"

uint8 inportb (uint16 _port) {
	uint8 rv;
	asm volatile ( "inb %1, %0"
                   : "=a"(rv)
                   : "Nd"(_port) );
	return rv;
}

void outportb (uint16 _port, uint8 _data) {
	asm volatile ( "outb %0, %1" : : "a"(_data), "Nd"(_port) );
}