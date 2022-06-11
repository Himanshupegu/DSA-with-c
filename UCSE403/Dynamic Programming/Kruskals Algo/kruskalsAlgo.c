#include <stdio.h>

typedef struct node
{
  int parent;
  int rank;
} dsuf;

void kruskalsAlgo(struct dsuf, int V, int E){
  
}

void sort(int Source[], int Destination[], int Weight[], int edges)
{

  for (int i = 0; i < edges - 1; i++)
  {
    int min = i;
    for (int j = i; j < edges; j++)
    {
      if (Weight[j] < Weight[min])
      {
        min = j;
      }
    }
    int temp;
    if (min != i)
    {
      temp = Weight[i];
      Weight[i] = Weight[min];
      Weight[min] = temp;

      temp = Source[i];
      Source[i] = Source[min];
      Source[min] = temp;

      temp = Destination[i];
      Destination[i] = Destination[min];
      Destination[min] = temp;
    }
  }
}

void printSortedEdges(int Source[], int Destination[], int Weight[], int edges)
{
  printf("\n\nSorting the weights in ascending order: \n\n");
  for (int i = 0; i < edges; i++)
  {
    printf("\nSource[%d] -> Destination[%d] = Weight[%d]", Source[i], Destination[i], Weight[i]);
  }
}

void printMST(int Source[], int Destination[], int Weight[], int edges)
{
  printf("\n\nMinimum Spanning Tree: \n\n");
  for (int i = 0; i < edges; i++)
  {
    printf("\nSource[%d] -> Destination[%d] = Weight[%d]", Source[i], Destination[i], Weight[i]);
  }
}

int main()
{
  int vertices, edges;
  printf("Enter the no. of vertices: ");
  scanf("%d", &vertices);
  printf("Enter the no. of edges: ");
  scanf("%d", &edges);
  int Source[edges], Destination[edges], Weight[edges];
  struct node *dsuf = (struct node *)malloc(vertices * sizeof(struct node));
  int dsuf[vertices];
  for (int i = 0; i < vertices; i++)
  {
    dsuf[i].parent = -1;
    dsuf[i].rank = 0;
  }

  for (int i = 0; i < edges; i++)
  {
    printf("Enter the Source[%d], Destination[%d], Weight[%d]: ", i + 1, i + 1, i + 1);
    scanf("%d %d %d", &Source[i], &Destination[i], &Weight[i]);
  }
  sort(Source, Destination, Weight, edges);
  printSortedEdges(Source, Destination, Weight, edges);

  return 0;
}