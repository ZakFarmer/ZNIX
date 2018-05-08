#ifndef SHELL_H
#define SHELL_H

#include "string.h"
#include "keyboard.h"
#include "screen.h"

void launch_shell() {
	printf("Launching ZNIX shell...\n\n");

	// This will do more in the future.

	shell_loop();
}

void shell_loop() {
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

#endif