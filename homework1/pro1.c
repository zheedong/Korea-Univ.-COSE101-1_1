#include <stdio.h>

int main()

{
	int a_in = 0;
	printf("Input an integer:");
	scanf_s("%d", &a_in);

	if (a_in % 2 == 1)
	{
		printf("%d is an odd integer\n", a_in);
	}

	if (a_in % 2 != 1)
	{
		printf("%d is an even integer\n", a_in);
	}

	return 0;
}