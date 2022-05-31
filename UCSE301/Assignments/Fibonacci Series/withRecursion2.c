#include <stdio.h>

int printFibonacci(int num)
{
  if (num <= 1)
  {
    return num;
  }
  else
  {
    int ans = (printFibonacci(num - 1) + printFibonacci(num - 2));
    return ans;
  }
}

int main()
{
  int num;
  printf("How many terms? ");
  scanf("%d", &num);
  if (num <= 0)
  {
    printf("Please enter a positive integer!!");
  }
  else
  {
    for (int i = 0; i < num; i++)
    {
      printf("%d ", printFibonacci(i));
    }
  }
}