// Find the Kth largest and Kth smallest number in an array
#include <stdio.h>
int maxMin(int arr[], int k, int n)
{
    int swap;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }
    return arr[k - 1];
}
int main()
{
    int k = 4;
    int n = 5;
    int arr[] = {7, 10, 4, 20, 15};
    printf("%d", maxMin(arr, k, n));
    return 0;
}