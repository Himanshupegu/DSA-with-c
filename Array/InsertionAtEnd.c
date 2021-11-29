//Array is not ful
#include <stdio.h>
int addAtEnd(int a[], int freePos, int data)
{
    a[freePos] = data;
    freePos++;
    return freePos;
}
int main()
{
    int a[10];
    int i, n, freePos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    freePos = n;
    freePos = addAtEnd(a, freePos, 69);
    for (i = 0; i < freePos; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}