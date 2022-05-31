#include <stdio.h>
int fun(char *p)
{
  char *q = p;
  while (*++p)
    ;
  return (p - q);
}
int main()
{
  char p = "Hi";
  int ans = fun(p);
  printf("%d", p);

  return 0;
}