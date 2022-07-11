#include <stdio.h>
#define INF 32000
#define v 6

int graph[v][v] = {
    {0, 3, 0, 0, 6, 5},
    {3, 0, 1, 0, 0, 4},
    {0, 1, 0, 6, 0, 4},
    {0, 0, 6, 0, 8, 5},
    {6, 0, 0, 8, 0, 2},
    {5, 4, 4, 5, 2, 0}};

int main()
{
  int noEdge = 0;
  int sum = 0;
  int x, y;
  int selected[v];
  for (int i = 0; i < v; i++)
  {
    selected[i] = 0;
  }

  selected[0] = 1;
  printf("Edge : Weight\n");

  while (noEdge < v - 1)
  {
    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < v; i++)
    {
      if (selected[i] == 1)
      {
        for (int j = 0; j < v; j++)
        {
          if (selected[j] == 0 && graph[i][j] != 0)
          {
            if (min > graph[i][j])
            {
              min = graph[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    sum += min;
    printf("%d -> %d : %d\n", x, y, graph[x][y]);
    selected[y] = 1;
    noEdge++;
  }
  printf("The cost of the MST = %d\n", sum);
  return 0;
}