#ifndef UTIL_H
#define UTIL_H

#include "types.h"

void memcpy(char *source, char *dest, int nbytes);
void memset(uint8 *dest, uint8 val, uint32 len);
void itoa(int n, char str[]);

#endif