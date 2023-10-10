#include <stdio.h>

int main(int argc, char *argv[]) {
	printf("Set of arguments:\n");

	for(int i = 0; i < argc; i++) {
		printf("Arguments #%d: %s\n", i, argv[i]);
	}

	return 0;
}