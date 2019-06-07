#include <stdio.h>

int main()
{
	int in1, in2, big, small, i, sum = 0;

	printf("Enter two integers :");
	scanf_s("%d %d", &in1, &in2);

	if (in1 >= in2)
	{
		big = in1;
		small = in2;
	}
	else
	{
		big = in2;
		small = in1;
	}

	i = small;

	while (i <= big)
	{
		sum = sum + i;
		i = i + 1;
	}

	printf("The sum of all integers between %d and %d is %d\n", in1, in2, sum);

	return 0;
}