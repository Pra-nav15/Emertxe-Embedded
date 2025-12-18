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
    int min_index, smallest;
    for (i = 0;i < size;i++)
    {
        min_index = i;
        smallest = arr[min_index];
        for (j = i+1;j < size;j++)
        {
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    printf("After Selection Sort:\n");
    for (i = 0;i < size;i++)
    {
        printf("%d ", arr[i]);
    }
}