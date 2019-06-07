#include <stdio.h>

int main() {
	int base =-1;
	int exponent = -1;
	int i = 1;
	int res = 1;

	while (base < 0) {
		printf("Enter the base number:");
		scanf_s("%d", &base);
	}

	while (exponent < 0) {
		printf("Enter the exponent number:");
		scanf_s("%d", &exponent);
	}

	while (i <= exponent) {
		res *= base;
		i++;
	}
	printf("%d^%d is %d\n", base, exponent, res);

	return 0;
}