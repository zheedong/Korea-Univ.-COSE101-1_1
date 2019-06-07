#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORKERS 100
#pragma warning(disable:4996)

//바이너리 모드 쓰지 말고 수정해보기

int count = 0;
char employee_name[MAX_WORKERS][100];

struct employee {
	int employee_id;
	char *name;
};

void menu1(FILE *num, struct employee emp[]) {
	if (count == 0) {
		num = fopen("employee.txt", "w+");
		printf("\nENTER THE EMPLOYEE ID :\n");
		scanf("%d", &emp[count].employee_id);

		printf("ENTER THE EMPLOYEE NAME :\n");
		emp[count].name = &employee_name[count][0];
		getchar();
		gets(emp[count].name);

		fwrite(&emp[count], sizeof(emp[count]), 1, num);
		count++;
		fclose(num);
	}
	else {
		num = fopen("employee.txt", "a");
		printf("\nENTER THE EMPLOYEE ID :\n");
		scanf("%d", &emp[count].employee_id);

		printf("ENTER THE EMPLOYEE NAME :\n");
		emp[count].name = &employee_name[count][0];
		getchar();
		gets(emp[count].name);

		fwrite(&emp[count], sizeof(emp[count]), 1, num);
		count++;
		fclose(num);
	}
}

void menu2(struct employee emp[]) {
	printf("==========================================\n");
	printf("ID         NAME\n");
	for (int i = 0; i < count; i++) {
		printf("%d          %s\n", emp[i].employee_id, emp[i].name);
	}
	printf("==========================================\n");
	system("pause");
}

void menu3(FILE *num, struct employee emp[]) {
	int ID_for_update;
	char NAME_for_update[80] = { '\0', };
	printf("==========================================\n\n");
	printf("ENTER THE EMPLOYEE ID FOR UPDATE :\n");
	scanf("%d", &ID_for_update);
	printf("ENTER THE EMPLOYEE NAME TO BE UPDATED :\n");
	gets();
	gets(emp[ID_for_update - 1].name);
	num = fopen("employee.txt", "w+");
	for (int j = 0; j < count; j++) {
		fwrite(&emp[j], sizeof(emp[j]), 1, num);
	}

	fclose(num);
}

int main() {
	FILE *empPtr = 0;
	struct employee emp[MAX_WORKERS];

	while (1) {
		int flow_con = 0;
		printf("==========================================\n");
		printf("MENU :\n");
		printf("==========================================\n");
		printf("1. Add a record\n");
		printf("2. Display the file\n");
		printf("3. Update the record\n");
		printf("4. Exit\n");
		printf("==========================================\n");
		printf("Enter your choice: ");

		while (flow_con != 1 && flow_con != 2 && flow_con != 3 && flow_con != 4) {
			scanf("%d", &flow_con);

			if (flow_con != 1 && flow_con != 2 && flow_con != 3 && flow_con != 4) {
				printf("Try again\n");
				getchar();
			}
		}

		switch (flow_con) {
		case 1:
			menu1(empPtr, emp);
			system("cls");
			break;
		case 2:
			menu2(emp);
			system("cls");
			break;
		case 3:
			menu3(empPtr, emp);
			system("cls");
			break;
		case 4:
			return 0;
		}
	}
}