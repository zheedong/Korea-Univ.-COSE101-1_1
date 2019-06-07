#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

int main() {
	char str1[80];
	char str2[80];
	char str3[80];
	char *ptr;
	int count[26] = { 0, };
	printf("Enter three lines of text:\n");
	gets(str1);
	gets(str2);
	gets(str3);

	for (int i = 0; i < 80; i++)
		str1[i] = tolower(str1[i]);
	for (int i = 0; i < 80; i++)
		str2[i] = tolower(str2[i]);
	for (int i = 0; i < 80; i++)
		str3[i] = tolower(str3[i]);

	for (int i = 'a'; i <= 'z'; i++) {
		ptr = strchr(str1, i);
		while (ptr != NULL)
		{
			count[i - 'a']++;
			ptr = strchr(ptr + 1, i);
		}
	}

	for (int i = 'a'; i <= 'z'; i++) {
		ptr = strchr(str2, i);
		while (ptr != NULL)
		{
			count[i - 'a']++;
			ptr = strchr(ptr + 1, i);
		}
	}

	for (int i = 'a'; i <= 'z'; i++) {
		ptr = strchr(str3, i);
		while (ptr != NULL)
		{
			count[i - 'a']++;
			ptr = strchr(ptr + 1, i);
		}
	}

	printf("\nThe total occurrences of each character:\n");
	for (int i = 'a'; i <= 'z'; i++) {
		printf("%c:%3d\n", i, count[i - 'a']);
	}
	return 0;
}