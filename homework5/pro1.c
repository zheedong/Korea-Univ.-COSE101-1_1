#include <stdio.h>
#include <time.h>

int main() {
	srand(time(NULL));
	int array[20];
	int check;
	int random;

	for (int j = 0; j <= 19; j++) {
		check = 0;
		random = rand() % 20 + 1;
		for (int i = 0; i <= j; i++) {
			if (array[i] == random) {
				check = 1;
				j--;
			}
		}
		if (check == 0) {
			array[j] = random;
		}
	}
	printf("Nonrepetitive array values are:\n");
	for (int i = 0; i <= 19; i++) {
		printf("Array[ %d ] = %d\n", i, array[i]);
	}
	return 0;
}