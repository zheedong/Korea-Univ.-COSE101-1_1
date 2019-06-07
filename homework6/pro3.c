#include <stdio.h>

void conc(char *s1, const char *s2);

int main() {
	char string1[80];
	char string2[80];

	printf("Enter two strings: ");
	scanf_s("%s %s", string1, 80, string2, 80);
	
	conc(string1, string2);

	printf("%s", string1);

	return 0;
}

void conc(char *s1, const char *s2) {
	while ((*s1) != '\0') {
		s1++;
	}
	while ((*s1) = (*s2)) {
		s1++;
		s2++;
	}
}