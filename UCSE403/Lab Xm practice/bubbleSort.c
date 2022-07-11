#include <stdio.h>

void bubbleSort(int arr[], int size){
	int flag;
	for(int i = 0; i < size - 1; i++){
		flag = 0;
		for(int j = 0; j < size -1 - i; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if(flag == 0){
			break;
		}
	}
}

void display(int arr[],int size)
{
    printf("\nAfter bubble sorting array elements are as follows:\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {2, 1, 5, 6, 3, 7, 8, 9, 10, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);
    display(arr, size);

	return 0;
}