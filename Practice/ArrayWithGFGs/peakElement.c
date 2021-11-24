//An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
#include <stdio.h>
int peakElement(int arr[], int n)
{
    int max = 0;
    int maxPos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxPos = i;
        }
    }
    return maxPos;
}
int main()
{
    int n = 5;
    int arr[] = {1, 2, 3, 7, 4};
    printf("%d", peakElement(arr, n));
    return 0;
}