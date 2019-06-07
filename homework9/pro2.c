#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct _student {
	char name[30];
	int stuID;
	int grade;
	char major[30];
}stu;

int main() {
	FILE *stuPtr = fopen("student_file.txt", "w");
	stu sd[5];
	stu sd_from_file[5];
	int search = 0;
	char buffer[1000] = { '\0', };
	
	for (int i = 0; i < 5; i++) {
		printf("Name Student_number Grade Major: ");
		scanf("%s %d %d %s", &sd[i].name, &sd[i].stuID, &sd[i].grade, &sd[i].major);
		fprintf(stuPtr, "%s %d %d %s ", sd[i].name, sd[i].stuID, sd[i].grade, sd[i].major);
	}
	fclose(stuPtr);

	printf("Insert the student number to find: ");
	scanf("%d", &search);

	FILE *stuPtr_2 = fopen("student_file.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(stuPtr, "%s %d %d %s ", &sd_from_file[i].name, &sd_from_file[i].stuID, &sd_from_file[i].grade, &sd_from_file[i].major);
	}

	for (int j = 0; j < 5; j++) {
		if (sd_from_file[j].stuID == search) {
			printf("The major of student with ID %d is %s.\n", sd_from_file[j].stuID, sd_from_file[j].major);
			fclose(stuPtr_2);
			return 0;
		}
	}
	printf("Student NOT found\n");
	fclose(stuPtr_2);
	return 0;
}