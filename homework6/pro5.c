#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main() {
	srand(time(NULL));
	int arr[SIZE];
	int i = 0;
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand() % 100 + 1;
	}
	for (i = 0; i < SIZE; i++) {
		printf("%d ", *(arr+i));
	}
	printf("\n");
	while (--i >= 0) {
		printf("%d ", *(arr + i));
	}
	return 0;
}