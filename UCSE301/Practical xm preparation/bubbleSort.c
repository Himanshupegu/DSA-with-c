#include <stdio.h>

void swap(int *i, int *j)
{
  int temp = *i;
  *i = *j;
  *j = temp;
}

void bubbleSort(int arr[], int size)
{
  int flag;
  for (int i = 0; i < size - 1; i++)
  {
    flag = 0;
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        // swap(&arr[j], &arr[j + 1]);
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;
      }
    }
    if (flag == 0)
    {
      break;
    }
  }
}

void findMidElement(int arr[], int size)
{
  int midElement = size / 2;
  printf("\nMid element of the sorted element is: ");
  printf("%d", arr[midElement]);
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
  int arr[] = {2, 5, 1, 6, 7, 9, 10, 15, 13, 4};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Given Array list\n");
  printArray(arr, size);

  bubbleSort(arr, size);
  printf("\nAfter calling bubbleSort function\n");
  printArray(arr, size);
  findMidElement(arr, size);

  return 0;
}