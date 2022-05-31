#include <stdio.h>
int ack(int m, int n)
{
  if (m == 0)
  {
    return n + 1;
  }
  else if ((m > 0) && (n == 0))
  {
    return ack(m - 1, 1);
  }
  else if ((m > 0) && (n > 0))
  {
    return ack(m - 1, ack(m, n - 1));
  }
}

int main()
{
  int A;
  A = ack(2, 3);
  printf("%d", A);
  return 0;
}