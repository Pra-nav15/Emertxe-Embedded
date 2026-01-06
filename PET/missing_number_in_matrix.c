#include<stdio.h>
#include<stdlib.h>
int main()
{
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int** arr = (int**)malloc(rows*sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        arr[i] = (int*)malloc(cols*sizeof(int));
    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
            scanf("%d", &arr[i][j]);
    }
    int sum = 0, large = 0;
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (large < arr[i][j])
            {
                large = arr[i][j];
            }
            sum += arr[i][j];
        }
    }
    int missing = 0;
    missing = (large * ((large + 1) / 2))-sum;
    printf("Missing Number is %d\n", missing);
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = missing;
                break;
            }
        }
    }
    printf("Transpose of Updated Matrix:\n");
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}