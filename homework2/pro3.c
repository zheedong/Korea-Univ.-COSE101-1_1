#include <stdio.h>

int main()
{
	int inp = 1000000;
	int res = 0;
	int i = 10000;
	int out = 0;

	while (inp > 99999)
	{
		printf("Enter a 5-digit number :");
		scanf_s("%d", &inp);
	}

	out = inp;

	while (i >= 1) {
		if (inp / i== 7)
		{
			res += 1;
			inp = inp - (inp / i) * i;
			i = i / 10;
		}
		else
		{
			inp = inp - (inp / i) * i;
			i = i / 10;
		}

	}

	printf("The number %d has %d seven(s) in it\n", out, res);

	return 0;
}