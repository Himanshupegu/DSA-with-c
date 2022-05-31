#include <stdio.h>

int main()
{
  // int arr[] = {10, 10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
  int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
  int size = sizeof(arr) / sizeof(arr[0]);

  int omax = 0;
  int dp[size];
  for (int i = 0; i < size; i++)
  {
    int max = 0;

    for (int j = 0; j < i; j++)
    {
      if (arr[j] < arr[i])
      {
        if (dp[j] > max)
        {
          max = dp[j];
        }
      }
    }
    dp[i] = max + 1;
    if (dp[i] > omax)
    {
      omax = dp[i];
    }
  }
  printf("%d", omax);
}