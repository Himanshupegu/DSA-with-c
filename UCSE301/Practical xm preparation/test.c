#include <stdio.h>

void swap(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

void bubbleSort(int arr[], int size){
	int flag;
	for(int i = 0; i < size - 1; i++){
		flag = 0;
		for(int j = 0; j < size - 1 - i; j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				flag = 1;
			}
		}
		if(flag == 0){
			break;
		}
	}
}
void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int arr[] = {4,2,1,6,8,12,10,5,15,17};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array\n");
	printArray(arr,size);

	bubbleSort(arr,size);
	printf("\nSorted array after calling bubbleSort function\n");
	printArray(arr,size);

	return 0;
}
