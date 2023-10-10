#include <stdio.h>

int main() {
	int a, b, c;
	printf("The equation view is ax + b = c\nEnter a\n");
	scanf("%d", &a);
	printf("Enter b\n");
	scanf("%d", &b);
	printf("Enter c\n");
	scanf("%d", &c);
	printf("Answer:\nx = %d\n", (c-b)/a);
}