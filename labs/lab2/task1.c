#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the array size\n");
    scanf("%d", &size);

    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand()%100;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}