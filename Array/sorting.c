#include <stdio.h>
void sort(int a[], int n)
{
    int x;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    printf("The shorted array is as follows: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[10];
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, n);
    return 0;
}