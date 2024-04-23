// Написать программу, в которой реализовать набор функций по работе со стеком:
//     Организовать хранение стека в памяти.
//     Реализовать добавление значения в стек.
//     Реализовать извлечение значения из стека.
//     Реализовать просмотр верхнего значения стека.
//     Учесть при работе возможность переполнения стека.
// Получить результат работы программы для нескольких (не менее двух) запусков для каждой функции в различных состояниях стека.

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int max_size;
    int top;
    int *items;
};

struct Stack *New_Stack(int capacity) { // создание стэка с вместимостью capacity
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));

    stack->max_size = capacity;
    stack->top = -1;
    stack->items = (int*) malloc(sizeof(int) *capacity);
    
    return stack;
}

int is_empty(struct Stack *stack) { // проверка пустой ли стэк
    return stack->top == -1;
}

int is_full(struct Stack *stack) { // проверка полный ли стэк 
    return stack->top == stack->max_size - 1;
}

int add(struct Stack *stack, int x) { // добавление значения в стэк
    if (is_full(stack)) {
        printf("Stack overflow\n");
        return 1;
    }

    stack->items[++stack->top] = x;
}

int extract(struct Stack *stack) { // извлечение верхнего значения из стэка
    if(is_empty(stack)) {
        printf("Stack is empty\n");
        return 1;
    }

    return stack->items[stack->top--];
}

int peek(struct Stack *stack) { // просмотр верхнего значения стэка
     if(!is_empty(stack)) {
        return stack->items[stack->top];
    } else {
        return 1;
    }
}

int main () {
    struct Stack *stack = New_Stack(10);
    add(stack, 1);
    add(stack, 2);
    add(stack, 3);

    printf("%d\n", peek(stack));
    extract(stack);

    
    printf("%d\n", peek(stack));
    extract(stack);
    
    printf("%d\n", peek(stack));
    extract(stack);

    add(stack, 1);

    if (is_empty(stack)) {
        printf("The stack is empty\n");
    }
    else {
        printf("The stack is not empty\n");
    }

    return 0;
}