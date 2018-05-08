#include "include/screen.h"
#include "include/keyboard.h"
#include "include/string.h"

int kmain() {
	clear_screen();
	while(1) {
		printf("\nZNIX> ");

		string str = read_string();
		if (str_compare(str, "clear")) {
			clear_screen();
		} else {
			printf("\nInvalid command.");
		}

		printf("\n");
	}
}