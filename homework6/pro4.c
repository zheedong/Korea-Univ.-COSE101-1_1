#include <stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);

int main() {
	int result;
	int a, b;
	int menu = 0;
	while (1) {
		menu = 0;

		int(*func[3])(int, int) = { add, sub, mul };
		printf("0.Addition\n1.Subtraction\n2.Multiplication\n3.End\nselect the operation: ");
		scanf_s("%d", &menu);

		if (menu == 3) {
			printf("Exit\n");
			return 0;
		}
		printf("Enter the two numbers: ");
		scanf_s("%d %d", &a, &b);
		result = (*func[menu])(a, b);
		switch (menu) {
		case 0:
			printf("\n\t%d + %d = %d\n\n", a, b, result);
			break;
		case 1:
			printf("\n\t%d - %d = %d\n\n", a, b, result);
			break;
		case 2:
			printf("\n\t%d * %d = %d\n\n", a, b, result);
			break;
		default:
			printf("Try again\n");
			break;
		}
	}
}

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}