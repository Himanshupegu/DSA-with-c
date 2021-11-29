#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
}*top = NULL;

void push(int data){

	struct node *newNode;
	newNode = malloc(sizeof(newNode));
	if(newNode == NULL){
		printf("\nStack Overflow!!\n");
		exit(1);
	}
	newNode->data = data;
	newNode->link = top;
	top = newNode;
	printf("\nElement is pushed successfully.\n");
}

int isEmpty(){
	if(top == NULL)
		return 1;
	else
		return 0;
}

int pop(){

	struct node *temp;
	int value;
	if(isEmpty()){
		printf("\nStack Underflow\n");
		exit(1);
	}
	temp = top;
	value = temp->data;
	top = top->link;
	free(temp);
	temp = NULL;
	return value;
}

void print(){

	struct node *temp;
	temp = top;
	if(isEmpty()){
		printf("\nStack Underflow\n");
		exit(1);
	}
	while(temp){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("NULL\n\n");
}

int main(){

	int choice, data;
	do{
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Print all the elements of the stack");
		printf("\n0. Exit\n");

		printf("\nEnter your option >> ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice){
			case 1:
				printf("Enter the element you want to push: ");
				scanf("%d", &data);
				push(data);
				break;

			case 2:
				printf("\n%d is deleted\n",pop());
				break;

			case 3:
				print();
				break;

			case 0:
				printf("\nExit...\n\n");
				break;

			default:
				printf("\nINVALID OPTION\n\n Please try again!\n");
				break;

		}

	}while(choice != 0);

return 0;
}
