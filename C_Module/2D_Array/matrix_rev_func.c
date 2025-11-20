#include<stdio.h>
#include<stdlib.h>
void matrix_rev(int** ptr, int row, int col);
void matrix_2drev(int* ptr, int);
int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int** ptr = (int**)malloc(row * sizeof(int*));
    for (int i = 0;i < row;i++)
    {
        *(ptr+i) = (int *)malloc(col * sizeof(int));
    }
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            scanf("%d", &ptr[i][j]);
        }
    }
    matrix_rev(ptr, row, col);
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}
void matrix_rev(int** ptr, int row, int col)
{
    for (int i = 0;i < row;i++)
    {
        matrix_2drev(ptr[i], col);
    }
}
void matrix_2drev(int ptr[], int col)
{
    int temp;
    for (int i = 0;i < col / 2;i++)
    {
        temp = ptr[i];
        ptr[i] = ptr[col - i - 1];
        ptr[col - i - 1] = temp;
    }
}
