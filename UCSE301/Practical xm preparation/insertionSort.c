#include <stdio.h>

void insertionSort(int arr[], int size)
{
  int temp;
  for (int i = 0; i < size; i++)
  {
    temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
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
  int arr[] = {4, 1, 6, 2, 7, 9, 15, 18, 11, 3};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Given Array\n");
  printArray(arr, size);

  insertionSort(arr, size);
  printf("\nArray list after calling insertionSort function\n");
  printArray(arr, size);

  return 0;
}