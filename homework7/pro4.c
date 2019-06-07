#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char str[10][50];
	char tmp[50];
	for (int i = 0; i < 10; i++) {
		printf("Enter a string: ");
		gets(&str[i][0]);
	}
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 9; i++) {
			if (strcmp(&str[i], &str[i+1]) != -1) {
				strcpy(tmp, &str[i][0], 50);
				strcpy(&str[i][0], &str[i+1][0], 50);
				strcpy(&str[i+1][0], tmp, 50);
			}
		}
	}
	printf("\nThe strings in sorted order are:\n");
	for (int i = 0; i <= 9; i++) {
		printf("%s\n", &str[i][0]);
	}
	return 0;
}