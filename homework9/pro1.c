#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void eliminate(char *str, char ch) //두 문자가 연속으로 나오면 제거하는 함수
{
	for (; *(str + 1) != '\0'; str++)
	{
		if (*str == ch && *(str + 1) == ch)
		{
			strcpy(str, str + 1);
			str--;
		}
	}
}

int main() {
	char buffer[30];
	char buffer2[30];
	char toR[100] = { '\0', };
	char toW[100] = { '\0', };
	FILE *Read;
	FILE *Write;

	printf("Enter the name of file to read: ");
	gets(buffer);
	if (fopen(buffer, "r") == NULL) {
		printf("ERROR\n");
		return 1;
	}
	else {
		Read = fopen(buffer, "r");
		fread(toR, sizeof(toR), 1, Read);
	}
	printf("Enter the name of file to write: ");
	gets(buffer2);
	Write = fopen(buffer2, "w");

	strcpy(toW, toR);
	eliminate(toW, '\n');
	fwrite(toW, strlen(toW), 1, Write);

	printf("Copy txt complete!");
	fclose(Read);
	fclose(Write);
	return 0;
}