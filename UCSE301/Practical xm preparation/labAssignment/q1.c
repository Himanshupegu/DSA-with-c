#include <stdio.h>
#define N 21

void creatArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("\nEnter the element for index %d: ",i);
		scanf("%d",&arr[i]);
	}
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ",arr[i]);
	}
}
void insertion(int arr[], int size){
	int pos, data;
	printf("\nEnter the position you want to insert: ");
	scanf("%d",&pos);
	printf("\nEnter the data you want to insert: ");
	scanf("%d",&data);

	if(pos<0 || pos > size){
		printf("\nInvalid position");
	}
	else{
		for(int i = size - i; i >= pos - 1; i--){
			arr[i + 1] = arr[i];
		}
		arr[pos -1] = data;
	}
	printf("\n\nInserted successfully");
}
void deletion(int arr[], int size){
	int pos;
	printf("Enter the position from which you want to delete the data: ");
	scanf("%d",&pos);
	if(pos<0 || pos>size){
		printf("\nInvalid position");
	}
	else{
		for(int i = pos - 1; i < size - 1; i++){
			arr[i] = arr[i + 1];
		}
		size--;
	}
	printf("\n\nDeleted successfully");
	printf("\nUpdated array list: ");
        printArray(arr, size);
}
int main(){
	int arr[N];
	//int size = sizeof(arr) / sizeof(arr[0]);
	int size;
	printf("Enter the size of array(under 20)");
	scanf("%d",&size);
	if(size<0 || size > 20){
		printf("\nInvalid size!!\n");
	}
	else{
		creatArray(arr,size);
		printf("Array is crated successfully");
	}
	printf("Given array: ");
	printArray(arr,size);

	int choice;
	do{
		printf("\n1) Insertion\n");
		printf("2) Deletion\n");
		printf("\n3) Display Array");
		printf("\n0) Exit\n");
		printf(">> \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insertion(arr,size);
				break;
			case 2:
				deletion(arr,size);
				break;
			case 3:
				printArray(arr,size);
				break;
			case 0:
				printf("Exit");
				break;
			default:
				printf("Invalid choice");
				break;
		}
	}while(choice != 0);
return 0;
}

