#include <stdio.h>

int ulcase(char inp) {
	if (inp >= 'A' && inp <= 'Z') {
		return 0;
	}
	else if (inp >= 'a' && inp <= 'z') {
		return 1;
	}
	else {
		return 2;
	}
}

int main() {
	char inp;
	int che;

	printf("Enter the Character : ");
	scanf_s("%c", &inp);

	che = ulcase(inp);

	if (che == 0) {
		printf("%c: Uppercase", inp);
	}
	else if (che == 1) {
		printf("%c: Lowercase", inp);
	}
	else if (che == 2) {
		printf("INPUT IS NOT AN ALPHABET");
	}

	return 0;
}