#include<stdio.h>
#include<stdlib.h>
void intersection(int*,int*,int*,int*);
int main()
{
    int size1, size2, return_size = 0;
    scanf("%d %d", &size1, &size2);
    int* arr1 = (int*)malloc(size1 * sizeof(int));
    int* arr2 = (int*)malloc(size2 * sizeof(int));
    printf("Enter Elements of Array1 : ");
    for (int i = 0;i < size1;i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter Elements of Array2: ");
    for (int j = 0;j < size2;j++)
    {
        scanf("%d", &arr2[j]);
    }
    intersection(arr1, arr2, &size1, &size2);
    return 0;
}
void intersection(int* arr1, int* arr2, int* size1, int* size2)
{
    for (int i = 0;i < *size1;i++)
    {
        for (int k = i + 1;k < *size1;k++)
        {
            if (arr1[i] == arr1[k])
            {
                arr1[k] = arr1[*size1 - 1];
                (*size1)--;
            }
        }
    }
    for (int i = 0;i < *size2;i++)
    {
        for (int k = i + 1;k < *size2;k++)
        {
            if (arr2[i] == arr2[k])
            {
                arr2[k] = arr2[*size2-1];
                (*size2)--;
            }
        }
    }
    for (int i = 0;i < *size1;i++)
    {
        for (int k = 0;k < *size2;k++)
        {
            if (arr1[i] == arr2[k])
            {
                printf("%d ", arr1[i]);
            }
        }
    }
}