#include<stdio.h>
int main()
{
    int size = 5;
    int arr[size];
    int i, j;
    for (i = 0;i < size;i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0;i < size-1;i++)
    {
        for (j = 0;j < size - i - 1;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("After Bubble Sort:\n");
    for (i = 0;i < size;i++)
    {
        printf("%d ", arr[i]);
    }
}