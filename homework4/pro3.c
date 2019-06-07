#include <stdio.h>

int gcd(int u, int v) {

	if (v == 0) {
		return u;
	}
	else {
		return gcd(v, u%v);
	}
}

int main() {
	int u, v;

	do {
		printf("Enter two positive integers: ");
		scanf_s("%d %d", &u, &v);
		if (u <= 0 || v <= 0) {
			printf("Wrong Input, Try again!\n\n");
		}
	} while (u <= 0 || v <= 0);
	printf("GCD of %d and %d is %d.", u, v, gcd(u, v));

	return 0;
}