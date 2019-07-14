#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//stack code

struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printstack(StackNodePtr currentPtr);
void instructions();

int main() {
	StackNodePtr stackPtr = NULL;
	int choice;
	int value;

	instructions();
	printf("? ");
	scanf("%d", &choice);

	while (choice != 3) {
		switch (choice) {
		case 1:
			while (!getchar());
			printf("Enter a n integer: ");
			scanf("%d", &value);
			push(&stackPtr, value);
			printstack(stackPtr);
			break;

		case 2:
			while (!getchar());
			if (!isEmpty(stackPtr)) {
				printf("The popped value is %d. \n", pop(&stackPtr));
				printstack(stackPtr);
			}
			break;

		default:
			while (!getchar());
			printf("Invalid choice. \n\n");
			instructions();
			break;
		}
		printf("? ");
		scanf("%d", &choice);
	}
	printf("End of run. \n");
	return 0;
}

void push(StackNodePtr *topPtr, int info) {
	StackNodePtr newPtr;

	newPtr = malloc(sizeof(StackNode));

	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else {
		printf("%d not inserted. No memory available.\n", info);
	}
}

int pop(StackNodePtr *topPtr) {
	StackNodePtr tempPtr;
	int popValue;

	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}

int isEmpty(StackNodePtr topPtr) {
	return topPtr == NULL;
}

void printstack(StackNodePtr currentPtr) {
	if (currentPtr == NULL) {
		printf("The stack is empty.\n\n");
	}
	else {
		printf("The stack is:\n");

		while (currentPtr != NULL) {
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		printf("NULL\n\n");
	}
}

void instructions() {
	printf("Enter choice : \n");
	printf("\t 1 to push a value on the stack. \n");
	printf("\t 2 to pop a value off the stack. \n");
	printf("\t 3 to end program. \n");
}