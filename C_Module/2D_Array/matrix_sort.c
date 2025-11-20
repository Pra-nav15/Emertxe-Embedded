#include<stdio.h>
#include<stdlib.h>
void read_2d_array(int* arr, int rows, int cols);
void print_2d_array(int* arr, int rows, int cols);
void sort_2d_array(int* arr, int rows, int cols);
int main()
{
    int rows, cols;
    int** arr = malloc(rows * sizeof(int*));
    for (int i = 0;i < rows;i++)
    {
        *(arr + i) = malloc(cols * sizeof(int));
    }
    read_2d_array(arr, rows, cols);
    print_2d_array(arr, rows, cols);
    sort_2d_array(arr, rows, cols);
}
void read_2d_array(int* arr, int rows, int cols)
{

}