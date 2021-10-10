//Deleting the last node
//Insertion at the end of the list (Optimal one)
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} node;
node *addAtEnd(node *ptr, int data)
{
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
node *delLast(node *head)
{
    if (head == NULL)
        printf("List is already empty!");
    else if (head->link == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        node *temp2 = head;
        while (temp->link != NULL)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}
int main()
{
    node *head = NULL;
    head = malloc(sizeof(node));
    head->data = 45;
    head->link = NULL;
    node *ptr = head;
    ptr = addAtEnd(ptr, 96);
    ptr = addAtEnd(ptr, 69);
    ptr = addAtEnd(ptr, 90);
    head = delLast(head);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}