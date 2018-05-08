#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "screen.h"
#include "system.h"
#include "types.h"

string read_string() {
	char buffer;
	string str_buffer;

	uint8 i = 0;
	uint8 isReading = 1;

	while (isReading) {
		if (inportb(0x64) & 0x1) {
			switch (inportb(0x60)) {
				case 2:
					printchr('1');
					str_buffer[i] = '1';
					i++;
					break;
				case 3:
					printchr('2');
					str_buffer[i] = '2';
					i++;
					break;
				case 4:
					printchr('3');
					str_buffer[i] = '3';
					i++;
					break;
				case 5:
					printchr('4');
					str_buffer[i] = '4';
					i++;
					break;
				case 6:
					printchr('5');
					str_buffer[i] = '5';
					i++;
					break;
				case 7:
					printchr('6');
					str_buffer[i] = '6';
					i++;
					break;
				case 8:
					printchr('7');
					str_buffer[i] = '7';
					i++;
					break;
				case 9:
					printchr('8');
					str_buffer[i] = '8';
					i++;
					break;
				case 10:
					printchr('9');
					str_buffer[i] = '9';
					i++;
					break;
				case 11:
					printchr('0');
					str_buffer[i] = '0';
					i++;
					break;
				case 12:
					printchr('-');
					str_buffer[i] = '-';
					i++;
					break;
				case 13:
					printchr('=');
					str_buffer[i] = '=';
					i++;
					break;
				case 14:
					printchr('\b');
					i--;
					str_buffer[i] = 0;
					break;
				case 16:
					printchr('q');
					str_buffer[i] = 'q';
					i++;
					break;
				case 17:
					printchr('w');
					str_buffer[i] = 'w';
					i++;
					break;
				case 18:
					printchr('e');
					str_buffer[i] = 'e';
					i++;
					break;
				case 19:
					printchr('r');
					str_buffer[i] = 'r';
					i++;
					break;
				case 20:
					printchr('t');
					str_buffer[i] = 't';
					i++;
					break;
				case 21:
					printchr('y');
					str_buffer[i] = 'y';
					i++;
					break;
				case 22:
					printchr('u');
					str_buffer[i] = 'u';
					i++;
					break;
				case 23:
					printchr('i');
					str_buffer[i] = 'i';
					i++;
					break;
				case 24:
					printchr('o');
					str_buffer[i] = 'o';
					i++;
					break;
				case 25:
					printchr('p');
					str_buffer[i] = 'p';
					i++;
					break;
				case 26:
					printchr('[');
					str_buffer[i] = '[';
					i++;
					break;
				case 27:
					printchr(']');
					str_buffer[i] = ']';
					i++;
					break;
				case 28:
					i++;
					isReading = 0;
					break;
				case 30:
					printchr('a');
					str_buffer[i] = 'a';
					i++;
					break;
				case 31:
					printchr('s');
					str_buffer[i] = 's';
					i++;
					break;
				case 32:
					printchr('d');
					str_buffer[i] = 'd';
					i++;
					break;
				case 33:
					printchr('f');
					str_buffer[i] = 'f';
					i++;
					break;
				case 34:
					printchr('g');
					str_buffer[i] = 'g';
					i++;
					break;
				case 35:
					printchr('h');
					str_buffer[i] = 'h';
					i++;
					break;
				case 36:
					printchr('j');
					str_buffer[i] = 'j';
					i++;
					break;
				case 37:
					printchr('k');
					str_buffer[i] = 'k';
					i++;
					break;
				case 38:
					printchr('l');
					str_buffer[i] = 'l';
					i++;
					break;
				case 39:
					printchr(';');
					str_buffer[i] = ';';
					i++;
					break;
				case 44:
					printchr('z');
					str_buffer[i] = 'z';
					i++;
					break;
				case 45:
					printchr('x');
					str_buffer[i] = 'x';
					i++;
					break;
				case 46:
					printchr('c');
					str_buffer[i] = 'c';
					i++;
					break;
				case 47:
					printchr('v');
					str_buffer[i] = 'v';
					i++;
					break;
				case 48:
					printchr('b');
					str_buffer[i] = 'b';
					i++;
					break;
				case 49:
					printchr('n');
					str_buffer[i] = 'n';
					i++;
					break;
				case 50:
					printchr('m');
					str_buffer[i] = 'm';
					i++;
					break;
				case 51:
					printchr(',');
					str_buffer[i] = ',';
					i++;
					break;
				case 52:
					printchr('.');
					str_buffer[i] = '.';
					i++;
					break;
				case 53:
					printchr('/');
					str_buffer[i] = '/';
					i++;
					break;
				case 57:
					printchr(' ');
					str_buffer[i] = ' ';
					i++;
					break;
			}
		}
	}

	str_buffer[i] = 0;
	return str_buffer;
}

#endif