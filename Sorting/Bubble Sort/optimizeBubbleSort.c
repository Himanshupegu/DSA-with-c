#include <stdio.h>
#define N 10

int array[N];

void createArray(int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the element for %d index: ", i);
        scanf("%d", &array[i]);
    }
    printf("\nArray element are as follows:\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
void bubbleSort(int n)
{
    int temp, flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void display(int n)
{
    printf("\nAfter bubble sorting array elements are as follows:\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
int main()
{
    int n;
    printf("\nEnter the number of element(Max limit is 10): ");
    scanf("%d", &n);
    createArray(n);
    bubbleSort(n);
    display(n);
}