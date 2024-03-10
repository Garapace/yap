// Написать программу, выполняющую операцию c = a + b, целые числа a, b заданы в программе.
// Реализовать вывод результата в виде строки, пример "с=8".
#include <stdio.h>

int main() {
	int a, b;
	printf("Enter a\n");
	scanf("%d", &a);
	printf("Enter b\n");
	scanf("%d", &b);
	printf("Answer:\nc = %d\n", a+b);
	return 0;
}