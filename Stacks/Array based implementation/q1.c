// arr[0] as the top
#include <stdio.h>
#define MAX 10
int stackArray[N];
int first = -1;
int isFull()
{
    if (first == N - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if (first == -1)
    {
        return 1;
    }
    else
        return 0;
}
void push(int data)
{
    if (isFull())
    {
        printf("\nStack Overflow!!\n");
    }
    else
    {
        first++;
        for (int i = first; i > 0; i--)
        {
            stackArray[i] = stackArray[i - 1];
        }
        stackArray[0] = data;
    }
}
int pop()
{
    if (isEmpty())
    {
        printf("\nStack Underflow!!\n");
    }
    else
    {
        int value;
        value = stackArray[0];
        for (int i = 0; i < first; i++)
        {
            stackArray[i] = stackArray[i + 1];
        }
        first--;
        return value;
    }
}
void print()
{
    if (isEmpty())
    {
        printf("\nStack Underflow!!\n");
    }
    else
    {
        for (int i = 0; i <= first; i++)
        {
            printf("%d ", stackArray[i]);
            printf("\n");
        }
    }
}
int main()
{
    push(34);
    push(45);
    push(44);
    pop();
    print();
    return 0;
}