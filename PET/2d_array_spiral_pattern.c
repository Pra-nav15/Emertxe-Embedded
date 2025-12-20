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

    while (top <= bottom && left <= right)
    {
        for (int i = left;i <= right;i++)
        {
            printf("%d ", arr[top][i]);
        }
        top++;
        for (int i = top;i<=bottom;i++)
        {
            printf("%d ", arr[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right;i >= left;i--)
            {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom;i >= top;i--)
            {
                printf("%d ", arr[i][left]);
            }
            left++;
        }

    }
}




















