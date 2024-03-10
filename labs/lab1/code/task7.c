// Написать программу, которая дописывает в конец текстового файла указанную в программе строку.

#include <stdio.h>
#include <string.h>

int main() {
	FILE *input_file;
	char input_file_name[100], text[100], ch;
	
	printf("Enter the input file name\n");
	scanf("%s", input_file_name);

	printf("Enter the text you want to add\n");
	scanf("%s", text);
	strncat(text, "\n", 2);

	input_file = fopen(input_file_name, "a");
	if(input_file == NULL) {
		printf("Error, can`t open file\n");
		return 0;
	}
	
	fputs(text, input_file);
	fclose(input_file);
	return 0;
}