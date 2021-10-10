//Array is full
#include <stdio.h>
int addAtEnd(int a[], int b[], int n, int freePos, int data)
{
    int i;
    for (i = 0; i < n; i++)
        b[i] = a[i];
    b[freePos] = data;
    freePos++;
    return freePos;
}
int main()
{
    int a[3];
    int i, n, freePos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    freePos = n;
    int size = sizeof(a) / sizeof(a[0]);
    if (n == size)
    {
        int b[size + 2];
        freePos = addAtEnd(a, b, size, freePos, 69);
        for (i = 0; i < freePos; i++)
            printf("%d ", b[i]);
    }
    else
        printf("Array is not full!");
    return 0;
}