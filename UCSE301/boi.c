#include <stdio.h>
char currentMode = "College life";
int main()
{
  for (int i = 2021; i <= 2024; i++)
  {
    printf("%d ", i);
    printf("%c", currentMode);
  }

  return 0;
}
