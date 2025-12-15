#include<stdio.h>
#include<stdlib.h>
void value_insert_sort(int* arr,int size);
int main()
{
    int size,num;
    printf("Enter the Size of Array : ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));
    printf("Enter Array Elements :");
    for (int i = 0;i < size;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The Value to be inserted :");
    scanf("%d", &num);
    size = size + 1;
    arr = realloc(arr, size * sizeof(int));
    arr[size - 1] = num;
    value_insert_sort(arr,size);
    return 0;
}
void value_insert_sort(int *arr,int size)
{
    for (int i = 0;i < size;i++)
    {
        for (int j = i + 1;j < size;j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array Elements After Sorting :");
    for (int i = 0;i < size;i++)
    {
        printf("%d ", arr[i]);
    }
}