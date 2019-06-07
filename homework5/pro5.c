#include <stdio.h>

void sort(int array[6][5]);

int main() {
	int quiz[6][5]; //���� quiz ����, ���� �л�. ������ ���� ��հ� ����

	for (int i = 0; i < 5; i++) {
		printf("INDEX %d\n", i);
		printf("Enter 5 Quiz scores :\n");

		for (int j = 0; j < 5; j++) {
			scanf_s("%d", &quiz[j][i]);
		}
		printf("\n");
	}

	sort(quiz);

	printf("From Highest Scores to Lowest :\n");
	for (int k = 0; k < 5; k++) {
		printf("%d ", quiz[5][k]);
	}
	printf("\n");
	return 0;
}

void sort(int array[6][5]) {

	int hold = 0;

	for (int i = 0; i < 5; i++) { //�л����� ��� ���ϱ�. ���� �� 6�� ° �࿡ �Է�.
		int tmp = 0;
		for (int j = 0; j < 5; j++) {
			tmp += array[j][i];
		}
		array[5][i] = tmp / 5;
	}

	for (int m = 0; m < 5; m++) { //���� ����
		for (int k = 0; k < 4; k++) {
			if (array[5][k] < array[5][k + 1]) {
				hold = array[5][k];
				array[5][k] = array[5][k + 1];
				array[5][k + 1] = hold;
			}
		}
	}
}
