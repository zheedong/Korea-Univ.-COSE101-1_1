#include <stdio.h>
#define SIZE 30

void stringReverse(char strArray[]);

int main() {
	char strArray[SIZE] = "Print this string backward.";
	printf("%s\n", strArray);
	stringReverse(strArray);
	printf("\n");
	return 0;
}

void stringReverse(char array[]){
	char com = array[0];

	if (com != '\0') {
		stringReverse(++array);
		printf("%c", com);
	}
}