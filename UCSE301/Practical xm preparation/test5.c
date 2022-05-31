#include <stdio.h>

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
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;
      }
      if (flag = 0)
      {
        break;
      }
    }
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    printf("%d ", arr[i]);
  }
}

int main()
{
  int arr[] = {2, 6, 3, 8, 7};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("The array is:\n");
  printArray(arr, size);
  bubbleSort(arr, size);
  printf("\nafter bubble sorting the array is:\n");
  printArray(arr, size);

  return 0;
}
