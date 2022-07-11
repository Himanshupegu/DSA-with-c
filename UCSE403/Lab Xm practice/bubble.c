void bubbleSort(int arr[], int size){
	int temp;
	for (int i = 1; i < size; i++)
	{
		int j = i -1;
		temp = arr[i];
		while(j >= 0 && arr[j] > arr[temp]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}