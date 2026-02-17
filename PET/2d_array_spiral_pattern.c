#include<stdio.h>
#include<stdlib.h>
void spiral_pattern(int** arr, int rows, int cols);
int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    spiral_pattern(arr, rows, cols);
    return 0;
}
void spiral_pattern(int** arr, int rows, int cols)
{
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int arr2[rows][cols];
    int k = 0;
    while (top <= bottom && left <= right)
    {
        for (int i = left;i <= right;i++)
        {
            arr2[k / cols][k % cols] = arr[top][i];
            k++;
        }
        top++;
        for (int i = top;i<=bottom;i++)
        {
            arr2[k / cols][k % cols] = arr[i][right];
            k++;
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right;i >= left;i--)
            {
                arr2[k / cols][k % cols] = arr[bottom][i];
                k++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom;i >= top;i--)
            {
                arr2[k / cols][k % cols] = arr[i][left];
                k++;
            }
            left++;
        }

    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }
}




















