#include "../include/screen.h"

int cur_x = 0, cur_y = 0;
const uint8 SCREEN_WIDTH = 80;
const uint8 SCREEN_HEIGHT = 25;
const uint8 SCREEN_DEPTH = 2;

void clear_line(uint8 fromLine, uint8 toLine) {
	uint16 i = SCREEN_WIDTH * fromLine * SCREEN_DEPTH;
	string vidmem = (string)0xb8000;
	for (i; i < (SCREEN_WIDTH * (toLine + 1) * SCREEN_DEPTH); i++) {
		vidmem[i] = 0x0;
	}
}

void clear_screen() {
	clear_line(0, SCREEN_HEIGHT);
	cur_x = 0;
	cur_y = 0;
	cur_update();
}

void cur_update() {
	unsigned temp;

	temp = cur_y * SCREEN_WIDTH + cur_x;

	outportb(0x3D4, 14);
	outportb(0x3D5, temp >> 8);
	outportb(0x3D4, 15);
	outportb(0x3D5, temp);
}

void scroll_up(uint8 lineNum) {
	string vidmem = (string)0xb8000;
	uint16 i = 0;
	for (i; i < SCREEN_WIDTH * (SCREEN_HEIGHT - 1) * 2; i++) {
		vidmem[i] = vidmem[i + SCREEN_WIDTH * 2 * lineNum];
	}
	clear_line(SCREEN_HEIGHT - 1 - lineNum, SCREEN_HEIGHT - 1);

	if ((cur_y - lineNum) < 0) {
		cur_y = 0;
		cur_x = 0;
	} else {
		cur_y -= lineNum;
	}
	cur_update();
}

void new_line_check() {
	if (cur_y >= SCREEN_HEIGHT - 1) {
		scroll_up(1);
	}
}

void printchr(char c) {
	string vidmem = (string) 0xb8000;
	switch (c){
		case (0x08):
			if (cur_x > 0) {
				cur_x--;
				vidmem[(cur_y * SCREEN_WIDTH + cur_x) * SCREEN_DEPTH] = 0x00;
			}
			break;
		/*case (0x09):
			cur_x = (cur_x + 8) & ~(8 - 1);
			break;*/
		case ('\r'):
			cur_x = 0;
			break;
		case ('\n'):
			cur_x = 0;
			cur_y++;
			break;
		default:
			vidmem [((cur_y * SCREEN_WIDTH + cur_x)) * SCREEN_DEPTH] = c;
			vidmem [((cur_y * SCREEN_WIDTH + cur_x)) * SCREEN_DEPTH + 1] = 0x0F;
			cur_x++;
			break;
	}

	if (cur_x >= SCREEN_WIDTH) {
		cur_x = 0;
		cur_y++;
	}
	new_line_check();
	cur_update();
}

void printf(string str) {
	uint16 i = 0;
	uint8 len = strlen(str);
	for (i; i < len; i++) {
		printchr(str[i]);
	}
}