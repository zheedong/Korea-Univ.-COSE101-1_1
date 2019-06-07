#include <stdio.h>

int main() {
	int star = 1;
	int space = 0;
	int is1;
	int is2;
	int starC;
	while (star <= 9) {

		for (is1 = 1; is1 <= (9 - star) / 2; is1++) {
			printf(" ");
		}

		for (starC = 1; starC <= star; starC++) {
			printf("*");
		}

		for (is2 = 1; is2 <= (9 - star) / 2; is2++) {
			printf(" ");
		}

		printf("\n");
		star += 2;
	}

	star = 7;
	
	while (star >= 1) {

		for (is1 = 1; is1 <= (9 - star) / 2; is1++) {
			printf(" ");
		}

		for (starC = 1; starC <= star; starC++) {
			printf("*");
		}

		for (is2 = 1; is2 <= (9 - star) / 2; is2++) {
			printf(" ");
		}

		printf("\n");
		star -= 2;
	}

	return 0;
}