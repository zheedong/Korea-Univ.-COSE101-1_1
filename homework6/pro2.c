#include <stdio.h>

int strcmp(const char *s1, const char *s2);

int main() {
	char string1[80];
	char string2[80];

	printf("Enter two strings: ");
	scanf_s("%s %s", string1, 80, string2, 80);

	if (!strcmp(string1, string2))
		printf("%s and %s are equal\n", string1, string2);
	else
		printf("%s and %s are not equal\n", string1, string2);
	return 0;
}

int strcmp(const char *s1, const char *s2) {
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 != *s2)
			return 1;
		s1++;
		s2++;
	}
	if (*s1 != '\0' || *s2 != '\0') {
		return 1;
	}
	return 0;
}