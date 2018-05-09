#ifndef SCREEN_H
#define SCREEN_H

#include "system.h"
#include "string.h"

int cur_x, cur_y;

const uint8 SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH;

enum COLOUR {
	BLACK = 0x0,
	BLUE = 0x1,
	GREEN = 0x2,
	CYAN = 0x3,
	RED = 0x4,
	MAGENTA = 0x5,
	BROWN = 0x6,
	GREY = 0x7,
	DGREY = 0x8,
	LBLUE = 0x9,
	LGREEN = 0xA,
	LCYAN = 0xB,
	LRED = 0xC,
	LMAGENTA = 0xD,
	YELLOW = 0xE,
	WHITE = 0xF
};

void clear_line(uint8 fromLine, uint8 toLine);

void cur_update();

void clear_screen();

void new_line_check();

void printchr(char c, char colour);

void printf(string str, char colour);

void scroll_up(uint8 lineNum);

#endif