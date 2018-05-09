#include "../include/string.h"

uint16 strlen(string str) {
	uint16 i = 1;
	while (str[i++]);
	return --i;
}

uint8 str_compare(string str_1, string str_2) {
	uint8 size = strlen(str_1);

	if (size != strlen(str_1)) return 0;
	else {
		uint8 i = 0;
		for (i; i < size; i++) {
			if (str_1[i] != str_2[i]) return 0;
		}
	}

	return 1;
}

uint8 char_in_array(char chr, char array[], uint8 arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		if (array[i] == chr) {
			return 1;
		}
	}
	return 0;
}