#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n = 5;
    int arr[n];
    int* ptr = (int*)malloc(n * sizeof(int));
    for (int i = 0;i < n;i++)
    {
        scanf("%d", (ptr + i));
    }
    printf("Array elements are : ");
    for (int i = 0;i < n;i++)
    {
        printf("%d ", *(ptr + i));
    }
    if (ptr == NULL)
    {
        printf("Memory allocation failed");
    }
    free(ptr);
    return 0;
}