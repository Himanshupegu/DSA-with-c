#include <stdio.h>

void TOH(int num, char x, char y, char z)
{
  if (num > 0)
  {
    TOH(num - 1, x, z, y);
    printf("\nMove disk %d from peg %c to peg %c", num, x, y);
    TOH(num - 1, z, y, x);
  }
}

int main()
{
  int n;
  printf("Enter the number of disks: ");
  scanf("%d", &n);
  TOH(n, 'A', 'B', 'C');
}
