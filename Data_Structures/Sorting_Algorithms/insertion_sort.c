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
    int key;
    for (i = 1;i < size;i++)
    {
        key = arr[i];
        for (j = i-1;j>=0;j--)
        {
            if (key < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = key;
    }
    printf("After Insertion Sort:\n");
    for (i = 0;i < size;i++)
    {
        printf("%d ", arr[i]);
    }
}