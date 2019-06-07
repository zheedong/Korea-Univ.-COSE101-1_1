#include <stdio.h>

int main() {
	int i = 0;
	int cur;
	int out1 = 0;
	int out2 = 0;
	int out3 = 0;
	int out4 = 0;

	printf("Decimal\t\tBinary\n");
	while (i <= 15) {
		cur = i;

		out1 = cur / 8 == 0 ? 0 : 1;
		cur %= 8;
		out2 = cur / 4 == 0 ? 0 : 1;
		cur %= 4;
		out3 = cur / 2 == 0 ? 0 : 1;
		cur %= 2;
		out4 = cur / 1 == 0 ? 0 : 1;


		printf("%d\t\t%d%d%d%d\n", i, out1, out2, out3, out4);
		i++;
	}
	return 0;
}