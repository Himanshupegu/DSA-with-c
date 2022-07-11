#include <stdio.h>
#define INF 32000
#define V 6

int graph[V][V] = {
    {0, 3, 0, 0, 6, 5},
    {3, 0, 1, 0, 0, 4},
    {0, 1, 0, 6, 0, 4},
    {0, 0, 6, 0, 8, 5},
    {6, 0, 0, 8, 0, 2},
    {5, 4, 4, 5, 2, 0}};

int parent[V] = {0};

int findParent(int a)
{
  while (parent[a])
  {
    a = parent[a];
  }
  return a;
}

int isCycle(int a, int b)
{
  if (a != b)
  {
    parent[b] = a;
    return 1;
  }
  return 0;
}

int main()
{
  int no_edge = 0;
  int min, i, j, sum = 0;
  int x, y, a, b;

  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (graph[i][j] == 0)
      {
        graph[i][j] = INF;
      }
    }
  }

  printf("Edge : Weight\n");

  while (no_edge < V - 1)
  {
    min = INF;
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (min > graph[i][j])
        {
          min = graph[i][j];
          x = a = i;
          y = b = j;
        }
      }
    }
    a = findParent(a);
    b = findParent(b);

    if (isCycle(a, b) == 1)
    {
      sum += min;
      printf("%d -> %d : %d\n", x, y, graph[x][y]);
      no_edge++;
    }
    graph[x][y] = graph[y][x] = INF;
  }
  printf("Total cost of the graph %d\n", sum);

  return 0;
}