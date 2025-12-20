#include<stdio.h>
int main()
{
    int rows = 2, cols = 3;
    int arr[rows][cols];
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int largest = arr[0][0], smallest = arr[0][0];
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < cols;j++)
        {
            if (arr[i][j]>largest)
            {
                largest = arr[i][j];
            }
            if (arr[i][j]<smallest)
            {
                smallest = arr[i][j];
            }
        }
    }
    if (largest < smallest)
    {
        int temp = largest;
        largest = smallest;
        smallest = temp;
    }
    printf("Max: %d ", largest);
    printf("Min: %d ", smallest);
}