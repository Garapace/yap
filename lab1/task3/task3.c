#include <stdio.h>
// Написать программу, которая выводит в терминал набор аргументов вызова исполняемого файла, заданных в консоли.

int main(int argc, char *argv[]) { // argc - аргументы, поданные в консоль при запуске, argv - массив строк аргументов
	printf("Set of arguments:\n");

	for(int i = 0; i < argc; i++) {
		printf("Arguments №%d: %s\n", i+1, argv[i]);
	}
	return 0;
}