#include <stdio.h>

int fibonacciDp(int n)
{
  int qb[n + 2];
  qb[0] = 0;
  qb[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    qb[i] = qb[i - 1] + qb[i - 2];
  }
  return qb[n];
}

int main()
{
  int x;
  printf("Enter the number: ");
  scanf("%d", &x);

  printf("%d", fibonacciDp(x));
  return 0;
}