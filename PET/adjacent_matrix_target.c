#include<stdio.h>
#include<stdlib.h>
void adjacent_matrix_target(int** arr, int n, int target);
int main()
{
    int n, target;
    scanf("%d", &n);
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        arr[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &target);
    adjacent_matrix_target(arr, n, target);
    return 0;
}
void adjacent_matrix_target(int** arr, int n, int target)
{
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (j + 1 < n && arr[i][j] + arr[i][j + 1] == target)
            {
                printf("%d + %d = %d\n", arr[i][j], arr[i][j + 1], target);
            }
            if (i + 1 < n && arr[i][j] + arr[i+1][j] == target)
            {
                printf("%d + %d = %d\n", arr[i][j], arr[i+1][j], target);
            }
            if ((i + 1 < n && j + 1 < n) && (arr[i][j] + arr[i + 1][j + 1] == target))
            {
                printf("%d + %d = %d\n", arr[i][j], arr[i+1][j + 1], target);
            }
        }
    }
}