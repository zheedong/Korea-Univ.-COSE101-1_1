#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	char file_name[30];
	char find_word[30];
	char text[1000] = { '\0', };
	int total_word = 0;
	int found_word = 0;

	printf("Enter the file name and word : ");
	scanf("%s %s", file_name, find_word);

	if (fopen(file_name, "r") == NULL) {
		printf("ERROR\n");
		return 1;
	}
	else {
		FILE *ttPtr = fopen(file_name, "r");

		fread(text, sizeof(text), 1, ttPtr);
		for (int i = 0; i < 1000; i++) {
			if (text[i] == '\n' || text[i] == '.' || text[i] == '!' || text[i] == '?') {
				text[i] = ' '; //�����ȣ�� ����� �ٲ۴�
			}
		}
		char *ptr = strtok(text, " ");
		while (ptr != NULL) {
			total_word++; //���⸦ ������ �ڸ���
			if (strcmp(ptr, find_word) == 0) {
				found_word++; //ã�� �ܾ ���ڿ����� Ž��
			}
			ptr = strtok(NULL, " ");
		}
		printf("The finding ratio : %d/%d", found_word, total_word);
		fclose(ttPtr);
		return 0;
	}
}