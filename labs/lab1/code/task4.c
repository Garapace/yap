// Написать программу, решающую линейное уравнение ax+b=c, коэффициенты a, b, с которого запрашиваются при выполнении.
// Реализовать вывод результата в виде строки, пример "x=2.6".
#include <stdio.h>

int main() {
	double a, b, c;

	printf("The equation view is ax + b = c\nEnter a\n");
	scanf("%lf", &a);

	printf("Enter b\n");
	scanf("%lf", &b);

	printf("Enter c\n");
	scanf("%lf", &c);

	printf("Answer:\nx = %lf\n", (c-b)/a);
	
	return 0;
}