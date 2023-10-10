#include <stdio.h>
#include <string.h>

int main() {
	FILE *input_file, *output_file;
	char input_file_name[100], output_file_name[100], text[100], ch;

	printf("Enter the input file name\n");
	scanf("%s", input_file_name);

	printf("Enter the output file name\n");
	scanf("%s", output_file_name);

	printf("Enter the text you want to add\n");
	scanf("%s", text);
	strncat(text, "\n", 2);
	
	input_file = fopen(input_file_name, "r");
	if(input_file == NULL) {
		printf("Error, can`t read file\n");
		return 0;
	}

	output_file = fopen(output_file_name, "w");
	if(output_file == NULL) {
		printf("Error, can`t create file\n");
		return 0;
	}

	fputs(text, output_file);
	while((ch = fgetc(input_file)) != EOF) {
		fputc(ch, output_file);
	}

	fclose(input_file);
	fclose(output_file);
	return 0;
} 