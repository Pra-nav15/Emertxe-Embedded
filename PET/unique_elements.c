#include<stdio.h>
void unique_elements(int *arr,int size);
int main()
{
    int arr[] = { 1,2,5,7,1,3,5,2,8,9 };
    int size = (sizeof(arr) / sizeof(arr[0]));
    unique_elements(arr, size);
    return 0;
}
void unique_elements(int *arr,int size)
{
    int i, j, count, k = 0, result[size];
    for (i = 0;i < size;i++)
    {
        count = 0;
        for (j = 0;j < i;j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                count = 1;
                break;
            }
        }
        if (count == 0)
        {
            result[k++] = arr[i];
        }
    }
    for (int i = 0;i < k;i++)
    {
        printf("%d ", result[i]);
    }
}