#include <stdio.h>

void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = (low + 1);
  int j = high;

  do
  {
    while (arr[i] <= pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      swap(&arr[i], &arr[j]);
    }
  } while (i < j)
      swap(&arr[j], &arr[low]);
  return j;
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pt = partition(arr, low, high);
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
  int arr[] = {1, 5, 7, 8, 2, 4, 9, 10, 15, 11};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("\nUnsorted array\n");
  printArray(arr, size);

  quickSort(arr, 0, size - 1);
  printf("\nSorted array after calling quickSort function\n");
  printArray(arr, size);
  return 0;
}