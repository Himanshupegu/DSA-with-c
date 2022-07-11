#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low + 1;
	int j = high;

	do{
		while(arr[i] <= pivot){
			i++;
		}
		while(arr[j] > pivot){
			j--;
		}
		if(i < j){
			swap(&arr[i], &arr[j]);
		}

	}while(i < j);
	swap(&arr[j], &arr[low]);
	return j;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		int prt = partition(arr, low, high);
		quickSort(arr, low, prt);
		quickSort(arr, prt + 1, high);
	}
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {

        printf("%d ", arr[i]);
    }
}

int main(){

    int arr[] = {2, 1, 5, 6, 3, 7, 8, 9, 10, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

	printf("\nUnsorted array\n");
    printArray(arr, size);

    printf("\nSorted array after calling quickSort function\n");
    quickSort(arr, 0, size - 1);
    printArray(arr, size);


return 0;
}