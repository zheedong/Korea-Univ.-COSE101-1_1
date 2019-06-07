#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#pragma warning(disable:4996)

void enc(char plain[10][10], char cip[10]) {
	srand(time(NULL));
	int cho_plain = rand() % 10;
	int cho_num = rand() % 19 + 1;
	for (int i = 0; i < 10; i++) {
		if (plain[cho_plain][i] == '\0') {
			cip[i] = '\0';
			break;
		}
		cip[i] = plain[cho_plain][i] + cho_num;
	}
	printf("\t- Encryptor -\n");
	printf("Selected word: %s\n", &plain[cho_plain][0]);
	printf("Selected value of the Key: %d\n", cho_num);
	printf("Ciphertext: %s\n", cip);
}

void dec(char plain[10][10], char cip[10]) {
	char check[10];
	int exi = 0;
	printf("\t- Decoder -\n");
	printf("Ciphertext: %s\n\n\n", cip);
	
	for (int key = 1; key <= 19; key++) {		
		for (int i = 0; i < 10; i++) {
			if (cip[i] == '\0') {
				check[i] = '\0';
				break;
				}
			check[i] = cip[i] - key;
		}
		printf("> Guess %d <\n", key);
		printf("  Key: %d\n", key);
		printf("  Plaintext: %s\n", check);
		
		for (int i = 0; i < 10; i++) {
			if (strcmp(&plain[i][0], check) == 0) {
				printf("Found the correct answer!\n\n");
				printf("result:'%d' was selected as the Key.\n", key);
				printf("       '%s' was the Plaintext.\n", check);
				exi = 1;
				break;
			}
		}
		if (exi == 0)
			printf("Matching word not found.\n\n");
		else
			break;
	}
}

int main() {
	char plain[10][10] = { "craftbeer", "metallica", "whitewine", "champagne", "bourgogne", "sandiego", "lafayette", "pinotnoir", "sauvignon", "dondiablo"};
	char ciphertext[10];
	enc(plain, ciphertext);
	dec(plain, ciphertext);
	return 0;
}