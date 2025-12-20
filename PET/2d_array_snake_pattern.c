#include<stdio.h>
#include<stdlib.h>
void snake_pattern(int** arr, int size);
int main()
{
    int size = 3;
    int** arr = (int**)malloc(size * sizeof(int*));
    for (int i = 0;i < size;i++)
    {
        arr[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j < size;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    snake_pattern(arr, size);
    return 0;
}
void snake_pattern(int** arr, int size)
{
    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j < size;j++)
        {
            if (i % 2 == 0 || i == 0)
            {
                printf("%d\t", arr[i][j]);
            }
            else
            {
                printf("%d\t", arr[i][size-j-1]);
            }
        }
        printf("\n");
    }
}