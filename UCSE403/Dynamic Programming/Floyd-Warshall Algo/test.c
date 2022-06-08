// Floyd-Warshall Algorithm in C
#include <stdio.h>
// defining the number of vertices
#define n 4

#define INF 999

void printMatrix(int matrix[][n]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][n])
{
  int matrix[n][n], i, j, k;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < n; k++)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][n])
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int graph[n][n] = {{0, 8, INF, 1},
                     {INF, 0, 1, INF},
                     {4, INF, 0, INF},
                     {INF, 2, 9, 0}};
  floydWarshall(graph);
}