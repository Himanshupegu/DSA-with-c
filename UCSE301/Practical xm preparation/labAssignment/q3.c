#include <stdio.h>
void swap(int *i, int *j){
	int temp = *i;
	*i = *j;
	*j = temp;
}

int pertition(int arr[], int low, int high){
	int pivot = arr[low];
	int i = (low + 1);
	int j = high;

	do{
		while(arr[i]<=pivot){
			i++;
		}
		while(arr[j] > pivot){
			j--;
		}
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}while(i<j);
	swap(&arr[low],&arr[j]);
	return j;
}

void quickSort(int arr[],int low,int high){
	if(low < high){
		int pt = pertition(arr, low, high);
		quickSort(arr,low,pt - 1);
		quickSort(arr,pt + 1,high);
	}
}
void binarySearch(int arr[], int size){
	int element;
	printf("\n\nEnter the element you want to search: ");
	scanf("%d",&element);
	int first = 0;
	int last = size - 1;
	int mid;

	while(first<=last){
		mid = (first + last) / 2;
		if(element == arr[mid]){
			printf("\n%d is found at index %d",element,arr[mid]);
			break;
		}
		if(element > arr[mid]){
			first = mid+1;
		}
		else{
			last = mid - 1;
		}
	}
	if(first > last){
		printf("\n\n%d is not found.(Element is not in the list)",element);
	}
}
void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[] = {1, 5, 7, 8, 2, 4, 9, 10, 15, 11};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("Given array\n");
	printArray(arr,size);

	quickSort(arr,0,size - 1);
	printf("Sorted array after calling quickSort() function\n");
	printArray(arr,size);

	binarySearch(arr,size);

return 0;
}

