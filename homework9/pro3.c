#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int input1[2][3];
	int input2[2][3];
	int result[2][3];

	FILE *i1Ptr = fopen("input1.txt", "r");
	FILE *i2Ptr = fopen("input2.txt", "r");
	FILE *i3Ptr = fopen("result.txt", "w");

	if (fopen("input1.txt", "r") == NULL || fopen("input2.txt", "r") == NULL) {
		printf("ERROR\n");
		return 1;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			fscanf(i1Ptr, "%d", &input1[i][j]);
			fscanf(i2Ptr, "%d", &input2[i][j]);
			result[i][j] = input1[i][j] + input2[i][j];
		}
	}
	printf("input1 matrix:\n");
	printf("%d\t%d\t%d\t\n%d\t%d\t%d\n\n", input1[0][0], input1[0][1], input1[0][2], input1[1][0], input1[1][1], input1[1][2]);
	
	printf("input2 matrix:\n");
	printf("%d\t%d\t%d\t\n%d\t%d\t%d\n\n", input2[0][0], input2[0][1], input2[0][2], input2[1][0], input2[1][1], input2[1][2]);

	printf("result matrix:\n");
	printf("%d\t%d\t%d\t\n%d\t%d\t%d\n", result[0][0], result[0][1], result[0][2], result[1][0], result[1][1], result[1][2]);
	fprintf(i3Ptr, "%d\t%d\t%d\t\n%d\t%d\t%d\n", result[0][0], result[0][1], result[0][2], result[1][0], result[1][1], result[1][2]);

	fclose(i1Ptr);
	fclose(i2Ptr);
	fclose(i3Ptr);

	return 0;
}