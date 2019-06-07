#include <stdio.h>

int checkCase(char cha);
void convertCharCase(char *sPtr);

int main() {
	char arr[] = "PoINteR is vERy ImPorTAnt in C pRoGraMMing, SO STudEnt nEEd tO pRACtiCe using pointer";
	printf("Original String 1 :\n%s\n\n", arr);
	convertCharCase(arr);
	printf("Converted String 2 :\n%s", arr);
	return 0;
}

int checkCase(char cha) {
	if (cha >= 'A' && cha <= 'Z')
		return 0;
	else if (cha >= 'a' && cha <= 'z')
		return 1;
	else
		return 2;
}

void convertCharCase(char *sPtr) {
	while (*sPtr != '\0') {
		if (checkCase(*sPtr) == 1) {
			*sPtr -= 'a' - 'A';
		}
		else if (checkCase(*sPtr) == 0) {
			*sPtr += 'a' - 'A';
		}
		sPtr++;
	}
}