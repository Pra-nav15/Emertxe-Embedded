#include<stdio.h>
#include<stdlib.h>
void magic_square(int **arr,int num);
int main()
{
    int num;
    printf("Enter the Number for Magic Square\n");
    scanf("%d", &num);
    if (num % 2 != 0 && num != 0 && num > 0)
    {
        int** arr = (int**)calloc(num, sizeof(int*));
        for (int i = 0;i < num;i++)
        {
            arr[i] = (int*)calloc(num,sizeof(int));
        }
        magic_square(arr,num);
    }
    else
    {
        printf("For Magic Square positive odd numbers are required\n");
    }
    return 0;
}
void magic_square(int** arr, int num)
{
    int n = 1, i, j, rows, cols;
    i = 0, j = (num / 2);
    while (n <= num * num)
    {
        rows = i, cols = j;
        arr[i][j] = n++;
        i--;
        j++;
        if (i < 0)
        {
            i = num - 1;
        }
        if (j > num - 1)
        {
            j = 0;
        }
        if (arr[i][j] != 0)
        {
            i = rows + 1;
            j = cols;
        }
    }
    for (int i = 0;i < num;i++)
    {
        for (j = 0;j < num;j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0;i < num;i++)
    {
        free(arr[i]);
    }
    free(arr);
}