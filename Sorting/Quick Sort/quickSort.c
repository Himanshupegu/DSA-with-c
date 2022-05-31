#include <stdio.h>

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}

// Lomuto Partition
int partision(int arr[], int low, int high)
{

	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);

	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{

	if (low < high)
	{
		int pt = partision(arr, low, high);
		quickSort(arr, low, pt - 1);
		quickSort(arr, pt + 1, high);
	}
}

void printArray(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{

		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = {5, 1, 7, 4, 9, 3, 6, 2, 8, 0};
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("\nUnsorted array\n");
	printArray(arr, size);

	quickSort(arr, 0, size - 1);
	printf("\nSorted array after calling quickSort function\n");
	printArray(arr, size);
	printf("\n\n");
	return 0;
}
