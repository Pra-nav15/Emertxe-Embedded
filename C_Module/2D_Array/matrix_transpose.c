#include<stdio.h>
int main()
{
    int rows, cols;
    printf("Enter the rows and cols of matrix:");
    scanf("%d %d", &rows, &cols);
    int arr1[rows][cols];
    int result[cols][rows];
    printf("Read elements of Matrix : \n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Transpose of Matrix is given below :\n");
    for (int i = 0;i < cols;i++)
    {
        for (int j = 0;j < rows;j++)
        {
            result[i][j] = arr1[j][i];
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;

}