#include <stdio.h>
#define N 20

void createArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("Enter the element for index %d: ", i);
    scanf("%d", &arr[i]);
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
}

void merge(int arr[], int lb, int mid, int ub)
{
  int temp[N];
  int i = lb;
  int k = i;
  int j = mid + 1;

  while (i <= mid && j <= ub)
  {
    if (arr[i] <= arr[j])
    {
      temp[k] = arr[i];
      i++;
      k++;
    }
    else
    {
      temp[k] = arr[j];
      j++;
      k++;
    }
  }
  if (j > ub)
  {
    while (i <= mid)
    {
      temp[k] = arr[i];
      i++;
      k++;
    }
  }
  if (i > mid)
  {
    while (j <= ub)
    {
      temp[k] = arr[j];
      j++;
      k++;
    }
  }

  for (int p = lb; p <= ub; p++)
  {
    arr[p] = temp[p];
  }
}

void mergeSort(int arr[], int lb, int ub)
{
  if (lb != ub)
  {
    int mid;
    mid = (lb + ub) / 2;
    mergeSort(arr, lb, mid);
    mergeSort(arr, mid + 1, ub);
    merge(arr, lb, mid, ub);
  }
}
int main()
{
  int arr[N];
  int x;
  printf("\nEnter the size of array(under 20): ");
  scanf("%d", &x);

  createArray(arr, x);

  printf("Given array: ");
  printArray(arr, x);

  mergeSort(arr, 0, x);
  printf("\nAfter sorting: ");
  printArray(arr, x);
}