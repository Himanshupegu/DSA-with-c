#include <stdio.h>

void selectionSort(int arr[], int size){
	for(int i = 0; i < size - 1; i++){
		int min = i;
		for(int j = i + 1; j < size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(min != i){
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {2, 1, 5, 6, 3, 7, 8, 9, 10, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);
    print(arr, size);

	return 0;
}