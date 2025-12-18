#include<stdio.h>
#include<stdlib.h>
int main()
{
    int rows = 4, cols = 4;
    int** arr = (int**)calloc(rows,sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        arr[i] = (int*)calloc(cols,sizeof(int));
    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int** trans = (int**)calloc(rows,sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        trans[i] = (int*)calloc(cols,sizeof(int));
    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            trans[i][j] = arr[j][i];
        }
    }
    printf("Transpose of the Given Matrix:\n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d\t", trans[i][j]);
        }
        printf("\n");
    }

}