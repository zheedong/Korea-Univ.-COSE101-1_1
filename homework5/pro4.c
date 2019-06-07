#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	srand(time(NULL));
	int matrix1[5][6];
	int matrix2[5][6];
	int result[5][6];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			matrix1[i][j] = rand() % 100 + 1;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			matrix2[i][j] = rand() % 100 + 1;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}

	printf("matrix1:\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%6d", matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\nmatrix2:\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%6d", matrix2[i][j]);
		}
		printf("\n");
	}


	printf("\nresult:\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%6d", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}