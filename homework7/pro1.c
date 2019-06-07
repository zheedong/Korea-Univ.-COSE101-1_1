#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int total = 0;
	char num[6];
	for (int i = 0; i < 4; i++) {
		printf("Enter an integer string: ");
		scanf("%s",num);
		total += atoi(num);
	}
	printf("The total of the values is %d\n", total);
	return 0;
}