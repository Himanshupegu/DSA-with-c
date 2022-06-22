#include <stdio.h>

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(int a[], int size, int i)
{
  int max = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && a[left] > a[max])
  {
    max = left;
  };

  if (right < size && a[right] > a[max])
  {
    max = right;
  }

  if (max != i)
  {
    swap(&a[i], &a[max]);
    maxHeapify(a, size, max);
  }
}

void buildMaxHeap(int a[], int size)
{
  int x = (size / 2) - 1;
  for (int i = x; i >= 0; i--)
  {
    maxHeapify(a, size, i);
  }
}

void heapSort(int a[], int size)
{
  buildMaxHeap(a, size);
  for (int i = size - 1; i >= 0; i--)
  {
    swap(&a[0], &a[i]);
    maxHeapify(a, i, 0);
  }
}
void printMaxHeap(int a[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", a[i]);
  }
}

int main()
{
  int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  int size = sizeof(a) / sizeof(a[0]);

  buildMaxHeap(a, size);
  printf("Array representation of Max Heap\n");
  printMaxHeap(a, size);

  printf("\nAfter calling heapSort() function: \n");
  heapSort(a, size);
  printMaxHeap(a, size);

  return 0;
}