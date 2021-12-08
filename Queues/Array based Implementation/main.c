#include <stdio.h>
#define N 10

int queue[N];
int front = -1;
int rear = -1;

void enQueue(int data)
{

    if (rear == N - 1)
    {
        printf("Queue Overflow!!");
    }
    else if (front == -1 && rear == -1)
    {
        rear = front = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void deQueue()
{

    if (front == -1 && rear == -1)
    {
        printf("Queue Underflow!!");
    }
    else if (front == rear)
    {
        printf("\n%d is DeQueued from the Queue.\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("\n%d is DeQueued from the Queue.\n", queue[front]);
        front++;
    }
}

void print()
{

    if (rear == -1 && front == -1)
    {
        printf("Queue Underflow!!");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

void peek()
{

    if (rear == -1 && front == -1)
    {
        printf("\nQueue Underflow!!\n");
    }
    else
    {
        printf("\n%d is the fist element in the queue.\n", queue[front]);
    }
}
int main()
{

    enQueue(34);
    enQueue(45);
    enQueue(59);
    print();
    printf("\n");
    deQueue();
    print();
    peek();

    return 0;
}
