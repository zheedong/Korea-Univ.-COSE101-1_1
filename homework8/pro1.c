#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int stu = 0;

typedef struct class_grade {
	char name[30];
	int student_id;
	int attendence;
	int midterm_exam;
	int final_exam;
	int assignment;
	int term_project;
	int total_score;
}Grade;

typedef struct class_report {
	int attendence;
	int midterm_exam;
	int final_exam;
	int assignment;
	int term_project;
	int total_score;
}Report;

void go_back() {
	int i;
	printf("\nEnter 1 to Go Back : ");
	do {
		scanf("%d", &i);
		if (i != 1)
			printf("Try again\n");
		getchar();
	} while (i != 1);
}

void menu1(Grade std[80]) {
	system("cls");
	printf("===================================\n");
	printf("         Registered Student        \n");
	printf("===================================\n");

	if (stu == 0) {
		printf("There are no registered students\n");
	}
	else {
		for (int i = 0; i < stu; i++) {
			printf("%-10d     %s\n", std[i].student_id, std[i].name);
		}
	}
	printf("===================================\n");
	go_back();
}

void menu2(Grade std[80]) {
	system("cls");
	if (stu >= 80) {
		int che = 0;
		printf("You already enter all student.\nDo you want to reset all data?\n1 : Yes / 2 : No");
		do {
			scanf("%d", &che);
			if (che == 1) {
				stu = 0;
			}
			else if (che == 2) {
				go_back();
			}
			else {
				printf("Try again;");
				getchar();
			}
		} while (che == 1 || che == 2);
	}
	printf("===================================\n");
	printf("Student Name : ");
	getchar();
	gets(&std[stu].name);
	printf("Student ID : ");
	scanf("%d", &std[stu].student_id);
	printf("Attendence (0 ~ 10) : ");
	scanf("%d", &std[stu].attendence);
	printf("Assignment (0 ~ 10) : ");
	scanf("%d", &std[stu].assignment);
	printf("Midterm Exam (0 ~ 30) : ");
	scanf("%d", &std[stu].midterm_exam);
	printf("Final Exam (0 ~ 30) : ");
	scanf("%d", &std[stu].final_exam);
	printf("Term Project (0 ~ 20) : ");
	scanf("%d", &std[stu].term_project);
	std[stu].total_score = std[stu].attendence + std[stu].assignment + std[stu].midterm_exam + std[stu].final_exam + std[stu].term_project;
	stu++;
	go_back();
}

void menu3(Grade std[80], Report ave, Report med) {
	system("cls");
	int i, j, temp;
	Grade std_copy[80] = { 0, };
	for (int i = 0; i < 80; i++) {
		std_copy[i] = std[i];
	}
	if (stu > 0) {
		int arr[6] = { 0, };
		for (int i = 0; i < stu; i++)
			arr[0] += std[i].attendence;
		for (int i = 0; i < stu; i++)
			arr[1] += std[i].midterm_exam;
		for (int i = 0; i < stu; i++)
			arr[2] += std[i].final_exam;
		for (int i = 0; i < stu; i++)
			arr[3] += std[i].assignment;
		for (int i = 0; i < stu; i++)
			arr[4] += std[i].term_project;
		for (int i = 0; i < stu; i++)
			arr[5] += std[i].total_score;
		ave.attendence = arr[0] / stu;
		ave.midterm_exam = arr[1] / stu;
		ave.final_exam = arr[2] / stu;
		ave.assignment = arr[3] / stu;
		ave.term_project = arr[4] / stu;
		ave.total_score = arr[5] / stu;

		for (i = 0; i < stu  - 1; i++) {
			for (j = 0; j < stu - 1 - i; j++) {
 				if (std_copy[j].attendence > std_copy[j + 1].attendence) {
					temp = std_copy[j].attendence;
					std_copy[j].attendence = std_copy[j + 1].attendence;
					std_copy[j + 1].attendence = temp;
				}
			}
		}
		for (int i = 0; i < stu - 1; i++) {
			for (int j = 0; j < stu - 1 - i; j++) {
				if (std_copy[j].assignment > std_copy[j + 1].assignment) {
					temp = std_copy[j].assignment;
					std_copy[j].assignment = std_copy[j + 1].assignment;
					std_copy[j + 1].assignment = temp;
				}
			}
		}
		for (int i = 0; i < stu - 1; i++) {
			for (int j = 0; j < stu - 1 - i; j++) {
				if (std_copy[j].midterm_exam > std_copy[j + 1].midterm_exam) {
					temp = std_copy[j].midterm_exam;
					std_copy[j].midterm_exam = std_copy[j + 1].midterm_exam;
					std_copy[j + 1].midterm_exam = temp;
				}
			}
		}
		for (int i = 0; i < stu - 1; i++) {
			for (int j = 0; j < stu - 1 - i; j++) {
				if (std_copy[j].final_exam > std_copy[j + 1].final_exam) {
					temp = std_copy[j].final_exam;
					std_copy[j].final_exam = std_copy[j + 1].final_exam;
					std_copy[j + 1].final_exam = temp;
				}
			}
		}
		for (int i = 0; i < stu - 1; i++) {
			for (int j = 0; j < stu - 1 - i; j++) {
				if (std_copy[j].term_project > std_copy[j + 1].term_project) {
					temp = std_copy[j].term_project;
					std_copy[j].term_project = std_copy[j + 1].term_project;
					std_copy[j + 1].term_project = temp;
				}
			}
		}
		for (int i = 0; i < stu - 1; i++) {
			for (int j = 0; j < stu - 1 - i; j++) {
				if (std_copy[j].total_score > std_copy[j + 1].total_score) {
					temp = std_copy[j].total_score;
					std_copy[j].total_score = std_copy[j + 1].total_score;
					std_copy[j + 1].total_score = temp;
				}
			}
		}
		if (stu % 2 == 1) {
			med.attendence = std_copy[(stu - 1) / 2].attendence;
			med.assignment = std_copy[(stu - 1) / 2].assignment;
			med.midterm_exam = std_copy[(stu - 1) / 2].midterm_exam;
			med.final_exam = std_copy[(stu - 1) / 2].final_exam;
			med.term_project = std_copy[(stu - 1) / 2].term_project;
			med.total_score = std_copy[(stu - 1) / 2].total_score;
		}
		else {
			med.attendence = (std_copy[stu / 2].attendence + std_copy[stu / 2 - 1].attendence) / 2;
			med.assignment = (std_copy[stu / 2].assignment + std_copy[stu / 2 - 1].assignment) / 2;
			med.midterm_exam = (std_copy[stu / 2].midterm_exam + std_copy[stu / 2 - 1].midterm_exam) / 2;
			med.final_exam = (std_copy[stu / 2].final_exam + std_copy[stu / 2 - 1].final_exam) / 2;
			med.term_project = (std_copy[stu / 2].term_project + std_copy[stu / 2 - 1].term_project) / 2;
			med.total_score = (std_copy[stu / 2].total_score + std_copy[stu / 2 - 1].total_score) / 2;
		}
	}
	else
		printf("There are no registered students\n\n");

	printf("Class report\n");
	printf("========================================\n");
	printf("Field         Average  ¦¢    Median   \n");
	printf("========================================\n");
	printf("Attendence  :    %-2d    ¦¢    %-2d     \n", ave.attendence, med.attendence);
	printf("Assignment  :    %-2d    ¦¢    %-2d     \n", ave.assignment, med.assignment);
	printf("Midterm     :    %-2d    ¦¢    %-2d     \n", ave.midterm_exam, med.midterm_exam);
	printf("Final       :    %-2d    ¦¢    %-2d     \n", ave.final_exam, med.final_exam);
	printf("Term Project:    %-2d    ¦¢    %-2d     \n", ave.term_project, med.term_project);
	printf("Total       :    %-2d    ¦¢    %-2d     \n", ave.total_score, med.total_score);
	printf("\n========================================\n");
	go_back();
}

void menu4(Grade std[80]) {
	system("cls");
	printf("=======================================\n");
	printf("              Final Grade              \n");
	printf("=======================================\n");
	printf("StudentID      Total Score    Grade\n");
	for (int i = 0; i < stu; i++) {
		char score;
		if (std[i].total_score >= 90)
			score = 'A';
		else if (std[i].total_score >= 80 && std[i].total_score < 90)
			score = 'B';
		else if (std[i].total_score >= 70 && std[i].total_score < 80)
			score = 'C';
		else if (std[i].total_score < 70)
			score = 'D';
		else
			score = 'F';
		printf("%10d        %3d           %c\n", std[i].student_id, std[i].total_score, score);
	}
	printf("=======================================\n");
	go_back();
}

int main() {
	Grade stu[80];
	Report ave = { 0, }, med = { 0, };
	for (;;) {
		system("cls");
		int flow = 0;
		printf("  COSE101 Grade Management System  \n");
		printf("===================================\n");
		printf("1. View Regeisterd Student\n");
		printf("2. Add Student\n");
		printf("3. Class Report\n");
		printf("4. View Final Grade\n");
		printf("5. Exit\n\n");
		printf("===================================\n");
		printf("Select Menu : ");
		scanf("%d", &flow);
		switch (flow) {
		case 1:
			menu1(stu);
			break;
		case 2:
			menu2(stu);
			break;
		case 3:
			menu3(stu, ave, med);
			break;
		case 4:
			menu4(stu);
			break;
		case 5:
			return 0;
		}
	}
}