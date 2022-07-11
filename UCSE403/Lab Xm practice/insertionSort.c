#include <stdio.h>

void insertionSort(int arr[], int size){
	int temp;
	for(int i = 1; i < size; i++){
		int j = i - 1;
		temp = arr[i];
		while(j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

int main(){


	return 0;
}