#include <stdio.h>
#define INF 32000

void insertValues(int v, int graph[v][v])
{
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      // printf("Enter the value for index [%d] [%d]: ", i, j);
      scanf("%d", &graph[i][j]);
    }
  }
}

void printAdjacencyMatrix(int v, int graph[v][v])
{
  for (int i = 0; i < v; i++)
  {
    printf("\n");
    for (int j = 0; j < v; j++)
    {
      printf("%d\t", graph[i][j]);
    }
  }
}

int primsAlgo(int v, int graph[v][v])
{
  int selected[v];
  int noEdge, sum = 0;
  int x, y;
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
  return sum;
}

int main()
{
  int v = 6;
  // printf("Enter no. of vertices: ");
  // scanf("%d", &v);
  int graph[v][v] = {
      {0, 3, 0, 0, 6, 5}, {3, 0, 1, 0, 0, 4}, {0, 1, 0, 6, 0, 4}, {0, 0, 6, 0, 8, 5}, {6, 0, 0, 8, 0, 2}, {5, 4, 4, 5, 2, 0}};
  // insertValues(v, graph);
  // printf("Your adjacency matrix is as follows: \n");
  // printAdjacencyMatrix(v, graph);

  int totalSum = primsAlgo(v, graph);
  printf("The cost of the MST = %d\n", totalSum);
  return 0;
}