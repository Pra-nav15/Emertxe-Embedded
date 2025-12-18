#include<stdio.h>
void remove_duplicates(int *arr,int size);
int main()
{
    int arr[] = { 1,2,5,7,1,3,5,2,8,9 };
    int size = (sizeof(arr) / sizeof(arr[0]));
    remove_duplicates(arr, size);
    return 0;
}
void remove_duplicates(int* arr, int size)
{
    int i, j, flag, k = 0, result[size];
    for (i = 0;i < size;i++)
    {
        flag = 0;
        for (j = 0;j < size;j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            result[k++] = arr[i];
        }
    }
    for (int i = 0;i < k;i++)
    {
        printf("%d ", result[i]);
    }
}