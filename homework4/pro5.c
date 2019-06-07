#include <stdio.h>

void i_to_a(int a) {
	char tmp;
	if (a >= 10) {
		i_to_a(a / 100);
		tmp = (a % 100) % 26 + 'A';
		printf("%c ", tmp);
	}
}

int main() {
	int n;

	while (1) {
		printf("Enter the inputs : ");
		scanf_s("%d", &n);

		if (n >= 100000 && n <= 999999) {
			break;
		}

		printf("Input Error!\n");
	}

	i_to_a(n);

	return 0;
}