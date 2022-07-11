#include <stdio.h>
// #define N 50

void merge(int arr[], int lb, int mid, int ub, int size)
{
	int tempArr[size];
	int i = lb;
	int k = i;
	int j = mid + 1;

	while (i <= mid && j <= ub)
	{
		if (arr[i] <= arr[j])
		{
			tempArr[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			tempArr[k] = arr[j];
			k++;
			j++;
		}
	}
	if (i > mid)
	{
		while (j <= ub)
		{
			tempArr[k] = arr[j];
			k++;
			j++;
		}
	}
	if (j > ub)
	{
		while (i <= mid)
		{
			tempArr[k] = arr[i];
			k++;
			i++;
		}
	}

	for (int p = lb; p <= ub; p++)
	{
		arr[p] = tempArr[p];
	}
}

void mergeSort(int arr[], int lb, int ub, int size)
{
	if (lb != ub)
	{
		int mid = (lb + ub) / 2;
		mergeSort(arr, lb, mid, size);
		mergeSort(arr, mid + 1, ub, size);
		merge(arr, lb, mid, ub, size);
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
	int arr[] = {2, 1, 5, 6, 3, 7, 8, 9, 10, 4};
	int size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, size, size);
	printArray(arr, size);

	return 0;
}