/*Написать программу, которая в качестве аргумента принимает размер произвольного массива, создает его, заполняет случайными числами 
с плавающей точкой в интервале (arg1, arg2), где arg1 и arg2 - также аргументы, вводимые при запуске программы, и выводит массив в консоль. 
Далее программа записывает массив в файл в отсортированном виде.

Сортировка должна быть организована с помощью функции.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(double array[], int size) { // сортировка пузырьком 
    int i, j, temp;
    for (i = 0; i < size-1; i++){
        for (j = 0; j < size-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int randomInt(int min, int max) { // функция создаёт случайное целое число в заданном в консоли диапазоне
    int num = (rand() % ((max - 1) - min + 1) + min);
    return num;
}

float randomFloat() { // создаёт случайное число вида 0.xxxxx
    float num = (float)rand() / RAND_MAX;
    return num;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
		printf("Error, try again\n");
		return 1;
	}

    int size = atoi(argv[1]);
    if (size <= 0) {
        printf("The size of the array must be a positive number\n");
        return 1;
    }

    int min = atoi(argv[2]); // проверка, что при вводе можеть быть ошибка минимального и максимального знаения интервала
    int max = atoi(argv[3]);
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }

    srand(time(NULL));

    double array[size];
    for (int i = 0; i < size; i++) { // вывод массива в консоль
        array[i] = randomInt(min, max) + randomFloat();
        printf("%f ", array[i]);
    }
    printf("\n");

    FILE *output_file = fopen("task4_files/file1.txt", "w");
    if(output_file == NULL) {
		printf("Error, can`t create file\n");
		return 1;
	}
    BubbleSort(array, size);

    for (int i = size-1; i >= 0; i--) { // записаь отсортированного массива в файл
        fprintf(output_file, "%lf ", array[i]);
    }
    fclose(output_file);

    return 0;
}