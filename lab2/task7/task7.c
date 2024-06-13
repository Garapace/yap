#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Написать программу, вычисляющую значение выражения, записанного в постфиксной (обратной польской) записи, 
// считываемого из входного файла. Считать, что выражение может содержать только цифры и знаки «+», «-», «*» и «/».

struct Stack {
    int max_size;
    int top;
    double *items;
};

struct Stack *New_Stack(int capacity) {
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));

    stack->max_size = capacity;
    stack->top = -1;
    stack->items = (double*) malloc(sizeof(int) *capacity);
    
    return stack;
}

int is_empty(struct Stack *stack) {
    return stack->top == -1;
}

int is_full(struct Stack *stack) {
    return stack->top == stack->max_size - 1;
}

int add(struct Stack *stack, double x) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
        return 1;
    }

    stack->items[++stack->top] = x;
}

int extract(struct Stack *stack) {
    if(is_empty(stack)) {
        printf("Stack is empty\n");
        return 1;
    }

    return stack->items[stack->top--];
}

int peek(struct Stack *stack) {
     if(!is_empty(stack)) {
        return stack->items[stack->top];
    } else {
        return 1;
    }
}

double calculate(char *str, int count) {
    double result = 0;
    struct Stack *nums = New_Stack(count);

    for (int i = 0; i < strlen(str); i++) {
    
        if(isdigit(str[i])) { // если символ в строке - число, добавляем его в стэк
            
            int index_start = i;
            while (str[i] != ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                i++;
                if (i == count) break;
            }
            int index_end = i;

            char num[index_end-index_start];
            int index_num = 0;
            for (int j = index_start; j < index_end; j++) {
                num[index_num] = str[j];
                index_num++;
            }
            add(nums, atof(num));
            i--;
        
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') { // если не число, извлекаем два числа из стэка, 
                                                                                       //выполняем операцию, и результат обратно в стэк
            double a = extract(nums);
            double b = extract(nums);

            switch (str[i]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
            }
            add(nums, result);
        }

    }
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
		printf("Error, try again\n");
		return 1;
	}

    FILE *input_file;

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Can`t open file\n");
        return 1;
    }

    char str[100];
    fgets(str, sizeof(str), input_file);

    int count = 0;
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        count++;
    }

    fclose(input_file);

    printf("Answer = %f\n", calculate(str, count));
    return 0;
}