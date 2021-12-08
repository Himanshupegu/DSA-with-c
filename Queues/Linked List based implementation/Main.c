#include <stdio.h>
#include <stdlib.h>

struct node
{

    int data;
    struct node *link;
};
struct node *front = 0;
struct node *rear = 0;

void enQueue(int data)
{

    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    if (rear == 0 && front == 0)
    {
        rear = front = newNode;
    }
    else
    {

        rear->link = newNode;
        // rear = rear->link;
        rear = newNode;
    }
}

void print()
{

    struct node *temp;
    if (rear == 0 && front == 0)
    {

        printf("\nQueue Underflow\n");
    }
    else
    {
        temp = front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}

void deQueue()
{

    struct node *temp;
    if (rear == 0 && front == 0)
    {

        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\n%d is deQueue from the queue\n", front->data);
        temp = front;
        front = front->link;
        free(temp);
        temp = NULL;
    }
}

int main()
{

    enQueue(45);
    enQueue(55);
    enQueue(65);
    print();
    deQueue();
    print();

    return 0;
}
