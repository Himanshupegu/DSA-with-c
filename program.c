// Selection sort
#include <stdio.h>
int main()
{
  int n, i, j, temp, min;
  printf("Enter the number of elements\n");
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (a[j] < a[min])
      {
        min = j;
      }
    }
    temp = a[i];
    a[i] = a[min];
    a[min] = temp;
  }
  printf("The sorted array is\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\n", a[i]);
  }
  return 0;
}