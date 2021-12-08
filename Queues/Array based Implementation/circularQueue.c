#include <stdio.h>
#define N 10

int queue[N];
int front = -1;
int rear = -1;

void enQueue(int data)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else if (((rear + 1) % N) == front)
    {
        printf("\nQueue Overflow!!");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = data;
    }
}

void deQueue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue Underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("\n%d is DeQueue.", queue[front]);
        front = (front + 1) % N;
    }
}

void print()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d ", queue[rear]);
    }
}

int main()
{
    enQueue(34);
    enQueue(45);
    enQueue(67);
    enQueue(69);
    print();
    printf("\n");
    deQueue();
    printf("\n");
    print();
    return 0;
}