#include <stdio.h>

int main() {
	int inp = 0;
	int i = 1;
	int i_10 = 0;
	int i_1 = 0;
	printf("Input the value of range edge :");
	scanf_s("%d", &inp);

	if (inp>=50 && inp<=100){
		printf("The Roman numeral equivalence Table from 1 to %d\n",inp);
		printf("------------------------------------------------\nDecimal Numbers Roman Numerals\n------------------------------------------------\n");
		do {
			printf("%d\t\t", i);
			i_10 = i / 10;
			i_1 = i % 10;
			switch (i_10) {
				case 1:
					printf("X");
					break;
				case 2:
					printf("XX");
					break;
				case 3:
					printf("XXX");
					break;
				case 4:
					printf("XL");
					break;
				case 5:
					printf("L");
					break;
				case 6:
					printf("LX");
					break;
				case 7:
					printf("LXX");
					break;
				case 8:
					printf("LXXX");
					break;
				case 9:
					printf("XC");
					break;
				case 10:
					printf("C");
					break;
				default:
					break;
			}

			switch (i_1) {
				case 1:
					printf("I");
					break;
				case 2:
					printf("II");
					break;
				case 3:
					printf("III");
					break;
				case 4:
					printf("IV");
					break;
				case 5:
					printf("V");
					break;
				case 6:
					printf("VI");
					break;
				case 7:
					printf("VII");
					break;
				case 8:
					printf("VIII");
					break;
				case 9:
					printf("IX");
					break;
				default:
					break;
			}
			printf("\n");
			i++;
		} while (i <= inp);
	}
	else {
		printf("Wrong Input! range edge should be from 50~100\n");
	}

	return 0;
}