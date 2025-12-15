#include<stdio.h>
void duplicate_elements(int* arr,int size);
int main()
{
    int arr[] = { 1,4,2,8,4,5,4,4,8,6,5};
    int size = (sizeof(arr) / sizeof(arr[0]));
    duplicate_elements(arr, size);
    return 0;
}
void duplicate_elements(int* arr, int size)
{
    int i, j,count=0;
    for (i = 0;i < size;i++)
    {
        count = 0;
        for (j = 0;j < i;j++)
        {
            if (arr[i] == arr[j])
            {
                count = 1;
                break;
            }
        }
        if (count == 0)
        {
            printf("%d ", arr[i]);
        }
    }
}
