#include <stdio.h> 

int main()
{
	int a, b, c, d, e, big1, big2, bigger, small1, small2, smaller, biggest, smallest = 0;
	printf("Input 5 integers :");
	scanf_s("%d%d%d%d%d", &a, &b, &c, &d, &e);
	
	if (a >= b)
	{
		big1 = a;
		small1 = b;
	}

	if (a < b)
	{
		big1 = b;
		small1 = a;
	}

	/*a�� b�� ��Ҹ� ���� ��*/

	if (c >= d)
	{
		big2 = c;
		small2 = d;
	}

	if (c < d)
	{
		big2 = d;
		small2 = c;
	}

	/*c�� d�� ��Ҹ� ��*/

	if (big1 >= big2)
	{
		bigger = big1;
	}

	if (big1 < big2)
	{
		bigger = big2;
	}

	if (bigger >= e)
	{
		biggest = bigger;
	}

	if (bigger < e)
	{
		biggest = e;
	}

	/*���� ū ���� Ȯ��*/

	if (small1 >= small2)
	{
		smaller = small2;
	}

	if (small1 < small2)
	{
		smaller = small1;
	}

	if (smaller >= e)
	{
		smallest = e;
	}

	if (smaller < e)
	{
		smallest = smaller;
	}

	/*���� ���� ���� Ȯ��*/

	printf("The largest value is %d\n", biggest);
	printf("The smallest value is %d\n", smallest);

	return 0;
}