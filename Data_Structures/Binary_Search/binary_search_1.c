#include<stdio.h>
void sort
int main()
{
    int size = 5;
    int arr[size];
    for (int i = 0;i < size;i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, size);
}