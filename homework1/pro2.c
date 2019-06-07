#include <stdio.h>

int main()
{
	int a_in, b_in = 0;
	printf("Enter two numbers : ");
	scanf_s("%d%d", &a_in, &b_in);

	printf("The sum is %d\n", a_in + b_in);
	printf("The product is %d\n", a_in * b_in);
	printf("The difference is %d\n", a_in - b_in);
	printf("The quotient is %d\n", a_in / b_in);
	printf("The remainder is %d\n", a_in % b_in);
	return 0;
}