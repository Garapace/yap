/*Создать структуру для хранения данных о названии и цене товара.
Считать из входного файла данные о товарах. Написать функцию для сортировки товаров по цене. Вывести отсортированные данные в выходной файл.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    double price;
} Product;

int compare(const void *x1, const void *x2) {
    Product *product_x1 = (Product*) x1;
    Product *product_x2 = (Product*) x2;
     if (product_x1->price < product_x2->price) {
        return -1;
    }
    else if (product_x1->price > product_x2->price) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
		printf("Error, try again\n");
		return 1;
	}

    FILE *input_file, *output_file;
    char line[100];
    
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Can`t open file\n");
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Can`t create file\n");
        fclose(input_file);
        return 1;
    }

    int num_lines = 0;
    while (fgets(line, 100, input_file) != NULL) {
        num_lines++;
    }

    rewind(input_file); // заново перемещаемся в начало файла для дальнейшей работы

    Product product[num_lines];
    int num_product = 0;
    while (fscanf(input_file, "%s %lf", product[num_product].name, &product[num_product].price) == 2) {
        num_product++;
    }

    qsort(product, num_product, sizeof(Product), compare);

    for (int i = 0; i < num_product; i++) {
        fprintf(output_file, "%s %.1f\n", product[i].name, product[i].price);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}