#include <stdio.h>
#include <stdlib.h>
#define M 20
int top = -1;
int arr[M];
int isFull()
{
    if (top == M - 1)
    {
        return 1;
    }
    else
        return 0;
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
void push(int pushData)
{
    if (isFull())
    {
        printf("\nStack Overflow.\n");
    }
    else
    {
        top++;
        arr[top] = pushData;
    }
}
void pop(int popData)
{
    int value;
    if (isEmpty())
    {
        printf("\nStack Underflow!!\n");
    }
    else
    {
        value = arr[top];
        top--;
        printf("\n%d is deleted.\n", value);
    }
}
int printTop()
{
    if (isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    return arr[top];
}
void print()
{
    if (isEmpty())
    {
        printf("Stack Underflow!!");
        exit(1);
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", arr[i]);
            printf("\n");
        }
    }
}
int main()
{
    int choice, pushData, popData;
    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the element in the stack\n");
        printf("0. Exit\n");
        printf("\nEnter your option >> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &pushData);
            push(pushData);
            printf("Data is pushed successfully.");
            break;
        case 2:
            pop(popData);
            break;
        case 3:
            printf("\nThe topmost element in the stack is %d.", printTop());
            break;
        case 4:
            print();
            break;
        case 0:
            printf("\n\nExit....");
            break;
        default:
            printf("\nINVALID OPTION!!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}