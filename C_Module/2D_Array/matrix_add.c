#include<stdio.h>
int main()
{
    int rows1, cols1, rows2, cols2;
    printf("Enter the rows and cols of matrix 1 :");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the rows and cols of matrix 2 :");
    scanf("%d %d", &rows2, &cols2);
    if (rows1 == rows2 && cols1 == cols2)
    {
        int arr1[rows1][cols1];
        int arr2[rows2][cols2];
        int result[rows1][rows2];
        printf("Read elements of Matrix 1 : \n");
        for (int i = 0;i < rows1;i++)
        {
            for (int j = 0;j < cols1;j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        }
        printf("Read elements of Matrix 2 : \n");
        for (int i = 0;i < rows2;i++)
        {
            for (int j = 0;j < cols2;j++)
            {
                scanf("%d", &arr2[i][j]);
            }
        }
        for (int i = 0;i < rows2;i++)
        {
            for (int j = 0;j < cols2;j++)
            {
                result[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        printf("Added Matrix is given below :\n");
        for (int i = 0;i < rows2;i++)
        {
            for (int j = 0;j < cols2;j++)
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Dimensions errors\n");
    }
    return 0;

}