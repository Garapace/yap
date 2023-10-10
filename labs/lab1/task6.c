#include <stdio.h>
#include <stdlib.h>

int main() {
	int count = 0;
	char input_file_name[100], output_file_name[100], line[100];
	FILE *input_file, *output_file;

	printf("Enter the input file name\n");
	scanf("%s", input_file_name);
	
	printf("Ënter the output file name\n");
	scanf("%s", output_file_name);

	input_file = fopen(input_file_name, "r");
	if(input_file == NULL) {
		printf("Error, can`t read file");
		return 0;
	}
	
	output_file = fopen(output_file_name, "w");
	if(output_file == NULL) {
		printf("Error, can`t create file");
		fclose(input_file);
		return 0;
	}
	
	while(fgets(line, 100, input_file) != NULL && count < 3) {
		fputs(line, output_file);
		count++;
	}

	fclose(input_file);
	fclose(output_file);
	return 0;
}