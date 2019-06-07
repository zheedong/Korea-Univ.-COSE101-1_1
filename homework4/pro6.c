#include <stdio.h>

void move(int from, int to)
{
	printf("%d --> %d\n", from, to);
}

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
		move(from, to);
	else
	{
		hanoi(n - 1, from, to, by);
		move(from, to);
		hanoi(n - 1, by, from, to);
	}
}

int main() {
	int level = 0;
	printf("Enter the starting number of disks: ");
	scanf_s("%d", &level);

	hanoi(level, 1, 2, 3);

	return 0;
}