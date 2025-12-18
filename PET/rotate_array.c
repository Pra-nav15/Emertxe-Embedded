#include<stdio.h>
#include<stdlib.h>
int main()
{
    int rows = 3, cols = 3;
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    printf("Enter the Elements in the array: \n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("The Array of Elements :\n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("The Array of Elements after Rotating 90 Clockwise :\n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d\t", arr[cols-j-1][i]);
        }
        printf("\n");
    }
     printf("The Array of Elements after Rotating 90 Anti-Clockwise :\n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d\t", arr[j][rows-i-1]);
        }
        printf("\n");
    }
     printf("The Array of Elements after Rotating 180 Anti-Clockwise and Clock-Wise:\n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d\t", arr[rows-i-1][cols-j-1]);
        }
        printf("\n");
    }
}