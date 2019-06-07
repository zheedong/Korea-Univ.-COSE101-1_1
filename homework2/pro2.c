#include <stdio.h>

int main()
{
	int inp = -1;
	int resu = 1;
	int i = 1;

	while (inp < 0)
	{
		printf("Enter a postive integer : ");
		scanf_s("%d", &inp);
	}

	if (inp > 0)
	{
		while (i <= inp)
		{
			resu = resu * i;
			i++;
		}
	}
	else
	{
		resu = 1;
	}

	printf("%d! is %d\n", inp, resu);

	return 0;
}