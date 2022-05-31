// Fibonacci Series without recursion
#include <stdio.h>

int main()
{
  int num, num1 = 0, num2 = 1;
  printf("How many terms? ");
  scanf("%d", &num);
  if (num <= 0)
  {
    printf("Please enter a positive integer!!");
  }
  else if (num == 1)
  {
    printf("The Fibonacci sequence of the number %d is: ", num);
    printf("%d", num);
  }
  else
  {
    printf("The Fibonacci sequence of the number %d are: ", num);
    printf("%d %d ", num1, num2);
    for (int i = 2; i < num; ++i)
    {
      int num3 = num1 + num2;
      printf("%d ", num3);
      num1 = num2;
      num2 = num3;
    }
    return 0;
  }
}