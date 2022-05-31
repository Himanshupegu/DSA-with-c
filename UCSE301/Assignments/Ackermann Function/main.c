// Ackermann Function
#include <stdio.h>

int ackermannFun(int m, int n)
{
  if ((m == 0) && (n > 0))
  {
    return n + 1;
  }
  else if ((m > 0) && (n == 0))
  {
    return ackermannFun(m - 1, 1);
  }
  else if ((m > 0) && (n > 0))
  {
    return ackermannFun(m - 1, ackermannFun(m, n - 1));
  }
  else
  {
    printf("Both m and n are zero. So, the Ackermann function will be ");
    return 0;
  }
}

int main()
{
  int m, n, ans;
  printf("Enter the value for m and n: ");
  scanf("%d %d", &m, &n);
  // printf("%d %d", m, n);
  ans = ackermannFun(m, n);
  printf("%d", ans);
  return 0;
}