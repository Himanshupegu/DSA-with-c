// Fibonacci Series with Recursion
#include <stdio.h>

void findFibonacci(int num)
{
  static int num1 = 0, num2 = 1, num3;
  if (num > 0)
  {
    num3 = num1 + num2;
    num1 = num2;
    num2 = num3;
    printf("%d ", num3);
    findFibonacci(num - 1);
  }
}

int main()
{
  int num;
  printf("Enter the number of element: ");
  scanf("%d", &num);
  printf("%d %d ", 0, 1);
  findFibonacci(num - 2);
}