// Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.

#include <stdio.h>

void main()
{
  // int arr[] = {10, 10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
  int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  int lis[size];
  for (int i = 0; i < size; i++)
  {
    int max = 0;
    for (int j = 0; j < i; j++)
    {
      if (arr[j] <= arr[i])
      {
        if (lis[j] > max)
        {
          max = lis[j];
        }
      }
    }
    lis[i] = max + 1;
  }

  int lds[size];
  for (int i = size - 1; i >= 0; i--)
  {
    int max = 0;
    for (int j = size - 1; j > i; j--)
    {
      if (arr[j] <= arr[i])
      {
        if (lds[j] > max)
        {
          max = lds[j];
        }
      }
    }
    lds[i] = max + 1;
  }
  int omax = 0;
  for (int i = 0; i < size; i++)
  {
    if (lis[i] + lds[i] - 1 > omax)
    {
      omax = lis[i] + lds[i] - 1;
    }
  }
  printf("%d", omax);
}