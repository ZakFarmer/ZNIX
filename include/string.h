#ifndef STRING_H
#define STRING_H

#include "types.h"
uint16 strlen(string str) {
	uint16 i = 1;
	while (str[i++]);
	return --i;
}

#endif