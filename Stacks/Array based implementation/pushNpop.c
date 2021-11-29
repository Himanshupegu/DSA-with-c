#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int top = -1;
int stackArr[MAX];
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow!\n");
        return;
    }
    top++;
    stackArr[top] = data;
}
int pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
        exit(1); // exit(1) means abnormal termination of the program
    }
    int value = stackArr[top];
    top--;
    return value;
}
void printList()
{
    if (top == -1)
    {
        printf("\nStack is underflow!");
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stackArr[i]);
        printf("\n");
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    // push(6);
    printf("\nElements in the stack\n");
    printList();
    // int data = pop();
    // printf("\nPop element is %d", data);
    // printf("\nElements after poping in the stack: ");
    // printList();

    return 0;
}