#include <stdio.h>
// Написать программу, которая выводит в терминал содержимое текстового файла, название которого передается при вызове исполняемого файла.
// Программа работает аналогично программе cat.

int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Error, try again\n");
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Error, file is empty\n");
		return 1;
	}

	char ch;
	while ((ch = fgetc(file)) != EOF) {
		putchar(ch);
	}

	fclose(file);
}