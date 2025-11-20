#include<stdio.h>
#include<stdlib.h>
void read_array_elements(int** arr, int rows, int cols);
void triangle(int **arr, int rows,int  cols);
void print_array_elements(int **arr, int rows, int cols);
int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        *(arr + i) = (int*)malloc(cols * sizeof(int));
    }
    read_array_elements(arr, rows, cols);
    triangle(arr, rows, cols);
    print_array_elements(arr, rows, cols);
}
void read_array_elements(int** arr, int rows, int cols)
{
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}
void triangle(int** arr, int rows, int cols)
{
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (j <= i)
            {
                arr[i][j];
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
}
void print_array_elements(int** arr, int rows, int cols)
{
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}