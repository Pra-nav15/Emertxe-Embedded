#include<stdlib.h>
#include<stdio.h>
int main()
{
    int rows, cols,temp;
    printf("Enter the Number of Rows and Coloumns :");
    scanf("%d %d", &rows, &cols);
    int** arr = (int**)malloc(sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        arr[i] = (int*)malloc(sizeof(cols));
    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols/2;j++)
        {
            temp=arr[i][j];
            arr[i][j]=arr[i][cols-j-1];
            arr[i][cols-j-1]=temp;
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i][j] = 1 - arr[i][j];
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
