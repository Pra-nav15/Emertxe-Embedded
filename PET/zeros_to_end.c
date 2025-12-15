#include<stdio.h>
void zeros_to_end(int* arr,int size);
int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0;i < size;i++)
    {
        scanf("%d", &arr[i]);
    }
    zeros_to_end(arr, size);
    return 0;
}
void zeros_to_end(int* arr,int size)
{
    int arr2[size], k = 0,j=0;
    for (int i = 0;i < size;i++)
    {
        arr2[i] = arr[i];
    }
    for (int i = 0;i < size;i++)
    {
        if (arr[i] == 0)
        {
            arr2[size - k - 1] = 0;
            k++;
        }
        else
        {
            arr2[j++] = arr[i];
        }
    }
    printf("After Moving All Zeros to End\n");
    for (int i = 0;i < size;i++)
    {
        printf("%d ", arr2[i]);
    }

}