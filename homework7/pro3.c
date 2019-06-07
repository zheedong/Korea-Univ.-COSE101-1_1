#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void elimination(char *str) {
	for (; *str != '\0'; str++)
	{
		if (*str == '.' || *str == '!' || *str == '?')
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}

int main() {
	char str[3][80];
	char *ptr;

	int count[20] = { 0, };
	printf("Enter three lines of text:\n");
	gets(&str[0][0]);
	elimination(&str[0][0]);
	gets(&str[1][0]);
	elimination(&str[1][0]);
	gets(&str[2][0]);
	elimination(&str[2][0]);

	for (int i = 0; i < 3; i++) {
		ptr = strtok(&str[i][0], " ");
		while (ptr != NULL)
		{
			count[strlen(ptr)]++;
			ptr = strtok(NULL, " ");
		}
	}

	for (int i = 0; i < 20; i++) {
		if (count[i] != 0) {	
			printf("%d words of length %d\n", count[i], i);
		}
	}

	return 0;
}