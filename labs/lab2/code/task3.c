// Написать программу, которая в качестве аргумента принимает размер произвольного массива, создает его, заполняет
// случайными числами с плавающей точкой в интервале (0, 1) и выводит этот массив в консоль.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
		printf("Error, try again\n");
		return 1;
	}

    int size = atoi(argv[1]); // atoi - переводит второй аргумент из терминала в целочисленное
    if (size <= 0) {
        printf("The size of the array must be a positive number\n");
        return 1;
    }

    srand(time(NULL)); // нужно чтобы создавался каждый раз новый массив

    float array[size];
    for (int i = 0; i < size; i++) {
        array[i] = (float)rand() / RAND_MAX; // RAND_MAX - это максимальное число, которое может возвратить функция rand()
        printf("%f ", array[i]);
    }

    return 0;
}