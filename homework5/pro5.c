#include <stdio.h>

void sort(int array[6][5]);

int main() {
	int quiz[6][5]; //행은 quiz 점수, 열은 학생. 마지막 행은 평균값 저장

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

	for (int i = 0; i < 5; i++) { //학생들의 평균 구하기. 구한 후 6번 째 행에 입력.
		int tmp = 0;
		for (int j = 0; j < 5; j++) {
			tmp += array[j][i];
		}
		array[5][i] = tmp / 5;
	}

	for (int m = 0; m < 5; m++) { //버블 정렬
		for (int k = 0; k < 4; k++) {
			if (array[5][k] < array[5][k + 1]) {
				hold = array[5][k];
				array[5][k] = array[5][k + 1];
				array[5][k + 1] = hold;
			}
		}
	}
}
