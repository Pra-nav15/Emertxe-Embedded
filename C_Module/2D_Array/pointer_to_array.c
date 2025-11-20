#include<stdio.h>
#include<stdlib.h>
void print_array(int* ptr, int rows, int cols);
int main()
{
    int rows, cols;
    printf("Enter the number of rows and cols: ");
    scanf("%d %d", &rows, &cols);
    int* ptr = (int*)calloc(rows * cols, sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &ptr[i * cols + j]);
        }
    }
    print_array(ptr, rows, cols);
}
void print_array(int* ptr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", ptr[i * cols + j]);
        }
        printf("\n");
    }
}