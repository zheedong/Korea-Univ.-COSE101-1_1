#include <stdio.h>

void magic(int *p1,int *p2,int *p3);

int main() {
	int p1, p2, p3;

	printf("Enter three numbers: ");
	scanf_s("%d %d %d", &p1, &p2, &p3);

	printf("Before: a = %d, b = %d, c = %d\n", p1, p2, p3);
	magic(&p1, &p2, &p3);
	printf("After: a = %d, b = %d, c = %d\n", p1, p2, p3);

	return 0;
}

void magic(int *p1, int *p2, int *p3) {
	int hold = 0;
	*p1 += 1;
	*p2 *= *p3;
	hold = *p3;
	*p3 = *p2;
	*p2 = hold;
}