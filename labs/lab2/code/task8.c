// Написать программу, реализующую перевод инфиксной записи арифметического выражения в постфиксную. 
// Исходное арифметическое выражение состоит из цифр, знаков «+», «-», «*», «/» и скобок.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Stack {
    int max_size;
    int top;
    char *items;
};

struct Stack_Double {
    int max_size;
    int top;
    double *items;
};

struct Stack *New_Stack(int capacity) {
    struct Stack *stack = (struct Stack*) malloc(sizeof(struct Stack));

    stack->max_size = capacity;
    stack->top = -1;
    stack->items = (char*) malloc(sizeof(int) *capacity);
    
    return stack;
}

struct Stack_Double *New_Stack_Double(int capacity) {
    struct Stack_Double *stack_double = (struct Stack_Double*) malloc(sizeof(struct Stack_Double));

    stack_double->max_size = capacity;
    stack_double->top = -1;
    stack_double->items = (double*) malloc(sizeof(int) *capacity);
    
    return stack_double;
}

int is_empty(struct Stack *stack) {
    return stack->top == -1;
}

int is_empty_double(struct Stack_Double *stack_double) {
    return stack_double->top == -1;
}

int is_full(struct Stack *stack) {
    return stack->top == stack->max_size - 1;
}

int is_full_double(struct Stack_Double *stack_double) {
    return stack_double->top == stack_double->max_size - 1;
}

int add(struct Stack *stack, char x) {
    if (is_full(stack)) {
        printf("Overflow\n");
        return 1;
    }

    stack->items[++stack->top] = x;
}

int add_double(struct Stack_Double *stack_double, double x) {
    if (is_full_double(stack_double)) {
        printf("Overflow\n");
        return 1;
    }

    stack_double->items[++stack_double->top] = x;
}

int extract(struct Stack *stack) {
    if(is_empty(stack)) {
        printf("Underflow\n");
        return 1;
    }

    return stack->items[stack->top--];
}

int extract_double(struct Stack_Double *stack_double) {
    if(is_empty_double(stack_double)) {
        printf("Underflow\n");
        return 1;
    }

    return stack_double->items[stack_double->top--];
}

int peek(struct Stack *stack) {
     if(!is_empty(stack)) {
        return stack->items[stack->top];
    } else {
        return 1;
    }
}

int Get_Piority(char oper) {
    switch (oper)
    {
        case '(': return 0;
        case ')': return 1;
        case '+': return 2;
        case '-': return 3;
        case '*': return 4;
        case '/': return 4;
        default: return 5;
    }
}

double calculate(char *str, int count) {
    double result = 0;
    struct Stack_Double *nums = New_Stack_Double(count);

    for (int i = 0; i < strlen(str); i++) {
    
        if(isdigit(str[i])) {
            
            int indexStart = i;
            while (str[i] != ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '('|| str[i] == ')') {
                i++;
                if (i == count) break;
            }
            int indexEnd = i;

            char num[indexEnd-indexStart];
            int indexNum = 0;
            for (int j = indexStart; j < indexEnd; j++) {
                num[indexNum] = str[j];
                indexNum++;
            }
            add_double(nums, atof(num));
            i--;
        
        } else if (str[i] != ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '('|| str[i] == ')') {
            double a = extract_double(nums);
            double b = extract_double(nums);

            switch (str[i]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
            }

            add_double(nums, result);
        }

    }
    return result;
}

char *Get_Expression(char *str, int count) {
    char *output = (char*) malloc(count *sizeof(char));
    struct Stack *oper = New_Stack(count);
    int indexNum = 0;

    for (int i = 0; i < strlen(str); i++) {

        if (str[i] == ' ' || str[i] == '=') {
            continue;
        }

        if(isdigit(str[i])) {
            
            int indexStart = i;
            while (str[i] != ' ' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')') {
                i++;
                if (i == count) break;
            }
            int indexEnd = i;

            char num[indexEnd - indexStart];
            
            for (int j = indexStart; j < indexEnd; j++) {
                output[indexNum] = str[j];
                indexNum++;
            }

            output[indexNum] = ' '; 
            indexNum++;
            i--;
        }

        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '('|| str[i] == ')') {

            if (str[i] == '(') {
                add(oper, str[i]);
            } else if (str[i] == ')') {
                char ch = extract(oper);

                while (ch != '(') {
                    output[indexNum] = ch;
                    indexNum++;
                    output[indexNum] = ' ';
                    indexNum++;
                    ch = extract(oper);
                }

            } else {
                if (!is_empty(oper)) {
                    if (Get_Piority(str[i]) <= Get_Piority(peek(oper))) {
                        output[indexNum] = extract(oper);
                        indexNum++;
                        output[indexNum] = ' ';
                        indexNum++;
                    } 
                }
                add(oper, str[i]);
            }
        }
    }

    while (!is_empty(oper)) {
        output[indexNum] = extract(oper);
        indexNum++;
        output[indexNum] = ' ';
        indexNum++;
    }

    return output;
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

    printf("Answer = %f\n", calculate(Get_Expression(str, count), count));
    return 0;
}