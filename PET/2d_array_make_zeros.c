#include<stdio.h>
int main()
{
    int n = 3;
    int arr[n][n];
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (arr[i][j] == 0 && i != j)
            {
                for (int k = 0;k < n;k++)
                {
                    arr[k][j] = 0;
                }
                for (int q = 0;q < n;q++)
                {
                    arr[i][q] = 0;
                }
                break;
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}