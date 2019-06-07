#include <stdio.h>

int main()
{
	int in1 = 0;
	int in2 = 0;

	printf("Input two integers :");
	scanf_s("%d %d", &in1, &in2);

	if (in1 % in2 == 0)
	{
		printf("%d is a multiple of %d by a factor of %d\n", in1, in2, in1 / in2);
	}
	else
	{
		printf("%d is not a multiple of %d\n", in1, in2);
	}

	return 0;
}