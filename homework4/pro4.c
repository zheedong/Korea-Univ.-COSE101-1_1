#include <stdio.h>

long long factorial(unsigned int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

long int combination(unsigned int x, unsigned int y) {
	return (factorial(x) / (factorial(y)*factorial(x - y)));
}

int main() {
	unsigned int n = 0;
	unsigned int r = 0;

	while (n < 5 || r < 5 || n>20 || r>20 || n < r) {
		printf("Enter the inputs :");
		scanf_s("%u %u", &n, &r);
		if (n < 5 || r < 5 || n>20 || r>20 || n < r) {
			printf("Input Error!\n\n");
		}
	}

	printf("nCr : %ld", combination(n, r));

	return 0;
}