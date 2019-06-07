#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip() {
	if (rand() % 2 == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int count = 0;
	int tmp = 0;

	srand(time(NULL));

	for (int i = 1; i <= 100; i++) {
		tmp = flip();
		if (tmp == 0) {
			printf("Tails ");
			count++;
		}
		else if (tmp == 1) {
			printf("Heads ");
		}

		if (i % 10 == 0) {
			printf("\n");
		}
	}
	
	printf("\nThe total number of Heads was %d\n", 100 - count);
	printf("The total number of Tails was %d\n", count);

	return 0;
}