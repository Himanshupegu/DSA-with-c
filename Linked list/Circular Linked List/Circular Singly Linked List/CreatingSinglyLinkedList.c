#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *circularSingly(int data)
{
    node *tempNode = malloc(sizeof(node));
    tempNode->data = data;
    tempNode->next = tempNode;
    return tempNode;
}
int main()
{
    node *tail;
    int data = 45;
    tail = circularSingly(data);

    printf("%d", tail->data);

    return 0;
}