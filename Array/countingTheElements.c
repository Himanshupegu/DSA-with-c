//Counting the elements and printing it's data
#include <stdio.h>
int main()
{
    int arr[] = {45, 98, 3};
    int n, i;
    n = sizeof(arr) / sizeof(int);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n%d", n);
    return 0;
}