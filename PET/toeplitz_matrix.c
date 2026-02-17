#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int toeplitz_matrix(int** arr,int rows,int cols);
int main()
{
    int rows, cols;
    printf("Enter the Rows and Coloumns :");
    scanf("%d %d", &rows, &cols);
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    printf("Enter the Matrix Elements :");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Given Matrix is:\n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int ret = toeplitz_matrix(arr, rows, cols);
    if (ret)
    {
        printf("Toeplitz Matrix\n");
    }
    else
    {
        printf("Not a Toeplitz Matrix");
    }
    return 0;
}
int toeplitz_matrix(int** arr, int rows, int cols)
{
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (j < cols-1 && i < rows-1)
            {
                if (arr[i][j] != arr[i + 1][j + 1])
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}