// Написать программу, которая генерирует массив из псевдослучайных целых чисел и записывает в файл в обратном порядке.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *output_file;
    int size;
    printf("Enter the array size\n");
    scanf("%d", &size);

    srand(time(NULL));

    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand()%101;
    }

    output_file = fopen("task2_files/file1.txt", "w");
    if(output_file == NULL) {
		printf("Error, can`t create file\n");
		return 1;
	}

    for (int i = 0; i < size; i++) { // вывод заполненного массива
        printf("%d ", array[i]);
    }
    printf("\n"); // переход на новую строку, чтобы в терминале всё круто было

    for (int i = size-1; i >= 0; i--) {
        fprintf(output_file, "%d ", array[i]);
    }

    fclose(output_file);
    return 0;
}