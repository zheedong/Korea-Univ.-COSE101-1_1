#include <stdio.h>

int main() {
	int inp = 0;
	int qun = 0;
	float total = 0;
	printf("Enter pairs of item numbers and quantities.\n");
	printf("Enter -1 for the item number to end input.\n");

	while (inp != -1) {
		scanf_s("%d", &inp);
		if (inp == -1) {
			break;
		}

		scanf_s("%d", &qun);

		switch (inp){
		case 1:
			total = total + 2.98 * qun;
			break;

		case 2:
			total = total + 4.50 * qun;
			break;

		case 3:
			total = total + 9.98 * qun;
			break;

		case 4:
			total = total + 4.49 * qun;
			break;

		case 5:
			total = total + 6.87 * qun;
			break;

		case -1:
			break;

		default:
			printf("Invalid product code:%d\n",inp);
			printf("            Qunatity:%d\n",qun);
			break;
		}
	}
	printf("The total retail value was:   %.2f\n", total);

	return 0;
}