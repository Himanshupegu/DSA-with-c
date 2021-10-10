//Deleting the first node
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
node *delFirst(node *head)
{
    if (head == NULL)
        printf("List ia already empty");
    else
    {
        node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    return head;
}
int main()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    node *current = malloc(sizeof(node));
    current->data = 98;
    current->link = NULL;
    head->link = current; // linking 1st node with 2nd node
    current = malloc(sizeof(node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current; //Linking 2nd node with 3rd node
    head = delFirst(head);
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}