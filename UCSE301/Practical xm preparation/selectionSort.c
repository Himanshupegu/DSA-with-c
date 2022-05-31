#include <stdio.h>

void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

void selectionSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    if (min != i)
    {
      int temp = arr[min];
      arr[min] = arr[j];
      arr[j] = temp;

     // swap(&arr[i], &arr[min]);
    }
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
  int arr[] = {4, 1, 6, 2, 7, 9, 15, 18, 1, 3};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Given Array\n");
  printArray(arr, size);

  selectionSort(arr, size);
  printf("\nArray list after calling selectionSort function\n");
  printArray(arr, size);
}