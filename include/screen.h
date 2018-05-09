#ifndef SCREEN_H
#define SCREEN_H

#include "system.h"
#include "string.h"

int cur_x, cur_y;

const uint8 SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH;

void clear_line(uint8 fromLine, uint8 toLine);

void cur_update();

void clear_screen();

void new_line_check();

void printchr(char c);

void printf(string str);

void scroll_up(uint8 lineNum);

#endif