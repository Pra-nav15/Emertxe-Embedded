#include<stdio.h>
#include<stdlib.h>
void matrix_rev(int** ptr, int row, int col);
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
}
void matrix_rev(int** ptr, int row, int col)
{
    printf("Orginal Matrix \n");
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j <col;j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
    printf("Reversed Matrix \n");
    for (int i = 0;i < row;i++)
    {
        for (int j = col-1;j >= 0;j--)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}