#include <stdio.h>
#include <stdlib.h>
#include <time.h> //글꼴은 나눔고딕코딩

void set_random(int random[]);
void ret_to_main();
void menu1();
void menu2(const int random[]);
void menu3(int random[]);
void menu4(const int random[]);
void menu5(const int random[]);
int basic_total(int voice, int text, float data);
int more_total(int voice, int text, float data);

int main() {//메인 메뉴
	int flow_control = 0;
	int random[10];
	set_random(random);

	while (1) {
		flow_control = 0;
		system("cls");
		printf("\n");
		printf("┌─────────────────────────────────────────────┐ \n");
		printf("│       KU Mobile Phone Bill Calculator       │ \n");
		printf("├─────────────────────────────────────────────┤ \n");
		printf("│  1 : Display plans                          │ \n");
		printf("│  2 : Usage information for past two months  │ \n");
		printf("│  3 : Input this month usage                 │ \n");
		printf("│  4 : Total fee for past 3 months            │ \n");
		printf("│  5 : Best plan recommendation               │ \n");
		printf("│  6 : Exit                                   │ \n");
		printf("└─────────────────────────────────────────────┘ \n");
		scanf_s("%d", &flow_control);

		switch (flow_control) { //switch 문으로 세부 메뉴 들어가기
		case 1:
			menu1();
			break;
		case 2:
			menu2(random);
			break;
		case 3:
			menu3(random);
			break;
		case 4:
			menu4(random);
			break;
		case 5:
			menu5(random);
			break;
		case 6:
			return 0;
		default:
			printf("Try again.\n");
			system("pause");
			getchar();
			break;
		}
	}
}

void set_random(int random[]) {
	srand(time(NULL));
	random[0] = rand() % 2; //basic or more (0이면 basic, 1이면 more)
	random[1] = rand() % 700 + 1; //2월 voice
	random[2] = rand() % 301; //2월 text
	random[3] = rand() % 14951 + 50; //2월 data * 100
	random[4] = rand() % 700 + 1; //3월 voice
	random[5] = rand() % 301; //3월 text
	random[6] = rand() % 14951 + 50; //3월 data * 100
	random[7] = 0; //4월 voice
	random[8] = 0; //4월 text
	random[9] = 0; //4월 data * 100
}

void ret_to_main() { //메인 메뉴로 돌아갈지 결정
	char Y_N;
	while (1) {
		printf("Back to main menu Y/N : ");
		getchar();
		scanf_s("%c", &Y_N);
		if (Y_N == 'Y' || Y_N == 'y'){
			getchar();
			break;
		}
		else if (Y_N != 'N' && Y_N != 'n'){
			printf("Error. Try again.\n");
			getchar();
		}
	}
}

void menu1() { //1번 메뉴
	system("cls");
	printf("┌─────────────────────────────────────────────┐ \n");
	printf("│                 Basic Plan                  │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│  Included in plan │   Additional usages     │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│ Voice     │ 500m free    │  ￦ 50 / 1m      │ \n");
	printf("│ Text      │ 100t free    │  ￦ 10 / 1t      │ \n");
	printf("│ Data      │ 2.00GB free  │  ￦ 1000 / 0.1GB │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│ Basic fee │ ￦ 20000                        │ \n");
	printf("└─────────────────────────────────────────────┘ \n\n");
	printf("┌─────────────────────────────────────────────┐ \n");
	printf("│               More Data Plan                │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│  Included in plan │   Additional usages     │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│ Voice     │ 300m free    │  ￦ 10 / 1m      │ \n");
	printf("│ Text      │ 100t free    │  ￦ 30 / 1t      │ \n");
	printf("│ Data      │ 30.00GB free │  ￦ 500 / 0.1GB  │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│ Basic fee │ ￦ 45000                        │ \n");
	printf("└─────────────────────────────────────────────┘ \n");
	ret_to_main();
}

void menu2(const int random[]) { //2번 메뉴
	system("cls");
	printf("┌─────────────────────────────────────────────┐ \n");
	printf("│           Last two months usage             │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│  My Plan : %-14s                   │ \n", random[0] == 0 ? "Basic Plan":"More Data Plan");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│           │    February    │      March     │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│ Voice     │     %3d min    │     %3d min    │ \n", random[1], random[4]);
	printf("│ Text      │     %3d text   │     %3d text   │ \n", random[2], random[5]);
	printf("│ Data      │  %6.2f GB     │  %6.2f GB     │ \n", (float)random[3] / 100, (float)random[6] / 100);
	printf("└─────────────────────────────────────────────┘ \n");	
	ret_to_main();
}

void menu3(int random[]) { //3번 메뉴
	int voice;
	int text;
	float data;
	system("cls");
	printf("================================\n");
	printf("Input your usages of voice : ");
	scanf_s("%d", &voice);
	printf("Input your usages of text : ");
	scanf_s("%d", &text);
	printf("Input your usages of data : ");
	scanf_s("%f", &data);
	random[7] = voice;
	random[8] = text;
	random[9] = (data * 100) / 1;
}

void menu4(const int random[]) { //4번 메뉴
	system("cls");
	int total_fee2 = 0;
	int total_fee3 = 0;
	int total_fee4 = 0;

	printf("┌──────────────────────────────────────────────────────────────┐ \n");
	printf("│                    My three months usage                     │ \n");
	printf("├──────────────────────────────────────────────────────────────┤ \n");
	printf("│  My Plan : %-14s                                    │ \n", random[0] == 0 ? "Basic Plan" : "More Data Plan");
	printf("├──────────────────────────────────────────────────────────────┤ \n");
	printf("│           │    February    │      March     │      April     │ \n");
	printf("├──────────────────────────────────────────────────────────────┤ \n");
	printf("│ Voice     │     %3d min    │     %3d min    │     %3d min    │ \n", random[1], random[4], random[7]);
	printf("│ Text      │     %3d text   │     %3d text   │     %3d text   │ \n", random[2], random[5], random[8]);
	printf("│ Data      │  %6.2f GB     │  %6.2f GB     │  %6.2f GB     │ \n", (float)random[3] / 100, (float)random[6] / 100, (float)random[9] / 100);
	printf("├──────────────────────────────────────────────────────────────┤ \n");
	if (random[0] == 0) {//basic plan
		printf("│ Extra Data│  %6.2f GB     │  %6.2f GB     │  %6.2f GB     │ \n",
			(float)random[3] / 100 < 2 ? 2 - (float)random[3] / 100 < 0.2 ? 2 - (float)random[3] / 100 : 0.2 : 0,
			(float)random[6] / 100 < 2 ? 2 - (float)random[6] / 100 < 0.2 ? 2 - (float)random[6] / 100 : 0.2 : 0,
			(float)random[9] / 100 < 2 ? 2 - (float)random[9] / 100 < 0.2 ? 2 - (float)random[9] / 100 : 0.2 : 0); //extra data

		total_fee2 = basic_total(random[1],random[2], (float)random[3] / 100);
		total_fee3 = basic_total(random[4], random[5], (float)random[6] / 100);
		total_fee4 = basic_total(random[7], random[8], (float)random[9] / 100);
	}
	else if (random[0] == 1) {//more data plan
		printf("│ Extra Data│  %6.2f GB     │  %6.2f GB     │  %6.2f GB     │ \n",
			(float)random[3] / 100 < 30 ? 30 - (float)random[3] / 100 < 3 ? 30 - (float)random[3] / 100 : 3 : 0,
			(float)random[6] / 100 < 30 ? 30 - (float)random[6] / 100 < 3 ? 30 - (float)random[6] / 100 : 3 : 0,
			(float)random[9] / 100 < 30 ? 30 - (float)random[9] / 100 < 3 ? 30 - (float)random[9] / 100 : 3 : 0); //extra data

		total_fee2 = more_total(random[1], random[2], (float)random[3] / 100);
		total_fee3 = more_total(random[4], random[5], (float)random[6] / 100);
		total_fee4 = more_total(random[7], random[8], (float)random[9] / 100);
	}
	printf("├──────────────────────────────────────────────────────────────┤ \n");
	printf("│ Total Fee │ ￦  %8d   │ ￦ %8d    │ ￦ %8d    │ \n", total_fee2, total_fee3, total_fee4);
	printf("└──────────────────────────────────────────────────────────────┘ \n");
	ret_to_main();
}

void menu5(const int random[]) { //5번 메뉴
	int basic = basic_total((random[1] + random[4] + random[7]) / 3, (random[2] + random[5] + random[8]) / 3, ((float)(random[3] + random[6] + random[9]) / 3) /100);
	int more = more_total((random[1] + random[4] + random[7]) / 3, (random[2] + random[5] + random[8]) / 3, ((float)(random[3] + random[6] + random[9]) / 3) / 100);
	system("cls");
	printf("┌─────────────────────────────────────────────┐ \n");
	printf("│           Average usage of 3-month          │ \n");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│  My Plan : %s                   │ \n", random[0] == 0 ? "Basic Plan    " : "More Data Plan");
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│  Average usage of voice : %6d            │ \n", (random[1]+random[4]+random[7])/3);
	printf("│  Average usage of text :  %6d            │ \n", (random[2] + random[5] + random[8]) / 3);
	printf("│  Average usage of data :  %6.2f            │ \n", ((float)(random[3] + random[6] + random[9]) / 3) / 100);
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│  Basic Plan Fee :     ￦%7d             │ \n", basic);
	printf("│  More Data Plan Fee : ￦%7d             │ \n", more);
	printf("├─────────────────────────────────────────────┤ \n");
	printf("│  We recommend to use %-14s         │ \n", basic > more ? "More Data Plan" : "Basic Plan");
	printf("└─────────────────────────────────────────────┘ \n");
	ret_to_main();
}

int basic_total(int voice, int text, float data) { //전체 요금 계산
	int total = 20000;
	if (voice > 500) {
		total += (voice - 500) * 50;
	}
	if (text > 100) {
		total += (text - 100) * 10;
	}
	if (data > 2) {
		total += (data - 2) * 10000;
	}
	return total;
}

int more_total(int voice, int text, float data) {
	int total = 45000;
	if (voice > 300) {
		total += (voice - 500) * 10;
	}
	if (text > 100) {
		total += (text - 100) * 30;
	}
	if (data > 30) {
		total += (data - 30) * 5000;
	}
	return total;
}