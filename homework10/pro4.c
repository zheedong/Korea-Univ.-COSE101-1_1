#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct node {
	char data[15];
	struct node *nextPtr;
};

typedef struct node Node;
typedef Node *NodePtr;

void printNode(NodePtr sPtr);
void insert_Node(NodePtr *sPtr, char *data);
void sorting(NodePtr *sPtr1, NodePtr *sPtr2, NodePtr *outPut);
void deletNode(NodePtr target);

int main() {
	FILE *ip1 = fopen("input1.txt", "r");
	FILE *ip2 = fopen("input2.txt", "r");
	FILE *out = fopen("output.txt", "w");
	char buffer[15];

	if (ip1 == NULL || ip2 == NULL) {
		printf("ERROR\n");
		return 1;
	}

	NodePtr startPtr1 = NULL, startPtr2 = NULL, outPut = NULL;

	for (int i = 0; i < 10; i++) {
		fscanf(ip1, "%s", buffer);
		insert_Node(&startPtr1, buffer);
	}

	for (int i = 0; i < 10; i++) {
		fscanf(ip2, "%s", buffer);
		insert_Node(&startPtr2, buffer);
	}

	printf("Input linked list 1: ");
	printNode(startPtr1);
	printf("Input linked list 2: ");
	printNode(startPtr2);

	sorting(&startPtr1, &startPtr2, &outPut);

	printf("Result linked list: ");
	printNode(outPut);

	NodePtr currentPtr = outPut;

	while (currentPtr != NULL) {
		fprintf(out, "%s\n", currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}

	fclose(ip1);
	fclose(ip2);
	fclose(out);
	return 0;
}

void printNode(NodePtr currentPtr) {
	while (currentPtr != NULL) {
		printf("%s -> ", &(currentPtr->data));
		currentPtr = currentPtr->nextPtr;
	}
	printf("EOF\n\n");
}

void insert_Node(NodePtr *sPtr, char *data) {
	NodePtr newPtr;
	NodePtr previousPtr;
	NodePtr currentPtr;

	newPtr = malloc(sizeof(Node));

	if (newPtr != NULL) {
		strcpy(newPtr->data, data);
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;
		while (currentPtr != NULL) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr; //*sPtr == currentPtr
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf("ERROR. There is no empty place in memory.");
	}
}

void sorting(NodePtr *sPtr1, NodePtr *sPtr2, NodePtr *outPut) {
	NodePtr currentPtr = NULL;
	NodePtr previousPtr = NULL;
	NodePtr prepreviousPtr = NULL;
	NodePtr new1 = NULL;

	currentPtr = *sPtr1;

	while (currentPtr != NULL) {
		prepreviousPtr = previousPtr;
		previousPtr = currentPtr;
		currentPtr = currentPtr->nextPtr;
	} //ù��° ��ũ�� �������� previousPtr�� �� ������

	currentPtr = *sPtr2; //1��° ��ũ �������� 2��° ��ũ ù��°�� ����
	previousPtr->nextPtr = currentPtr;


	new1 = malloc(sizeof(Node));
	*sPtr2 = new1;
	new1->nextPtr = *sPtr1;
	//new1 ��带 ó���� �߰�

	prepreviousPtr = *sPtr2;
	previousPtr = prepreviousPtr->nextPtr;
	currentPtr = previousPtr->nextPtr; //�ʱ� ����

	for (int i = 0; i < 21; i++) {
		prepreviousPtr = *sPtr2;
		previousPtr = prepreviousPtr->nextPtr;
		currentPtr = previousPtr->nextPtr; //�� ���� ���� �ʱ� ����
		for (int j = 0; j < 19; j++) {
			if (currentPtr != NULL) {
				if (strcmp(previousPtr->data, currentPtr->data) > 0) { //���� �ٲٱ�
					NodePtr temp;
					temp = currentPtr->nextPtr;
					prepreviousPtr->nextPtr = currentPtr;
					currentPtr->nextPtr = previousPtr;
					previousPtr->nextPtr = temp;
				}
			}
			prepreviousPtr = prepreviousPtr->nextPtr;
			previousPtr = prepreviousPtr->nextPtr;
			currentPtr = previousPtr->nextPtr; //�� ĭ �� �̵�
		}
	}
	*outPut = (*sPtr2)->nextPtr;
	//�ؿ����� �ߺ� ����
	previousPtr = *outPut;
	currentPtr = previousPtr->nextPtr;
	while (currentPtr != NULL) {
		if (strcmp(previousPtr->data, currentPtr->data) == 0) {
			deletNode(previousPtr);
			currentPtr = previousPtr->nextPtr;
		}
		NodePtr temp;
		temp = currentPtr->nextPtr;
		previousPtr = currentPtr;
		currentPtr = temp;
	}
}

void deletNode(NodePtr target) {
	NodePtr remove = target->nextPtr;
	target->nextPtr = remove->nextPtr;
	free(remove);
}