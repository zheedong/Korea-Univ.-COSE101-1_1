#include <stdio.h>

int main() {
	int i = 1;
	int inB = 0;
	int inp;

	do {
		printf("Enter the number:");
		scanf_s("%d", &inp);

		if (i == 1) {
			inB = inp;
		}
		else if (inp >= inB){
			inB = inp;
		}
		i++;
	} while (i <= 5);

	printf("Largest is %d\n", inB);

	return 0;
}