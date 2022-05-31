#include <stdio.h>
#define N 10

int array[N];

void creatArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter the input for index %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n\nArray element are as follow: ");
}

void insertionSort(int array[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {
        temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
} 

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
int main()
{
    int array[N];
    int n;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    creatArray(array, n);
    print(array, n);
    insertionSort(array, n);
    printf("\n\nAfter insertion sorting array element are as follow: ");
    print(array, n);
}