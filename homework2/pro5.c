#include <stdio.h>

int main()
{
	int peo, res = 0;
	int i = 1;
	while (i <= 4)
	{
		printf("Enter Employee %d's sales in dollars:", i);
		scanf_s("%d", &peo);
		if (peo >= 3000)
		{
			res = 200 + peo * 9 / 100;
		}
		else
		{
			res = 200;
		}
		printf("Employee %d's salary is : %d\n\n", i, res);
		i++;
	}
}