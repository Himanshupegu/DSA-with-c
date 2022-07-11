//Kruskal algorithm for minimum spanning tree

#include <stdio.h>

void printMST(int Source[], int Destination[], int Weight[], int edges)
{
  printf("\n\nMinimum Spanning Tree: \n\n");
  for (int i = 0; i < edges; i++)
  {
    printf("\nSource[%d] -> Destination[%d] = Weight[%d]", Source[i], Destination[i], Weight[i]);
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

int main(){
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    int Source[E], Destination[E], Weight[E];
    printf("Enter the edges and weights: \n");
    for (int i = 0; i < E; i++)
    {
        printf("Enter the source: ");
        scanf("%d", &Source[i]);
        printf("Enter the destination: ");
        scanf("%d", &Destination[i]);
        printf("Enter the weight: ");
        scanf("%d", &Weight[i]);
    }
    printSortedEdges(Source, Destination, Weight, E);
    printMST(Source, Destination, Weight, E);
    return 0;
}