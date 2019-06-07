#include <stdio.h>

int main()
{
	int inp, a, b, c, d, e, sum = 0;

	printf("Input:");
	scanf_s("%d", &inp);

	a = inp / 10000;
	inp = inp - a * 10000;

	b = inp / 1000;
	inp = inp - b * 1000;

	c = inp / 100;
	inp = inp - c * 100;

	d = inp / 10;
	e = inp % 10;

	if (a % 2 == 1)
	{
		sum = sum + a;
	}

	if (b % 2 == 1)
	{
		sum = sum + b;
	}

	if (c % 2 == 1)
	{
		sum = sum + c;
	}

	if (d % 2 == 1)
	{
		sum = sum + d;
	}

	if (e % 2 == 1)
	{
		sum = sum + e;
	}

	printf("Output:\n");
	printf("%d   %d   %d   %d   %d\n", e, d, c, b, a);
	printf("%d", sum);
}