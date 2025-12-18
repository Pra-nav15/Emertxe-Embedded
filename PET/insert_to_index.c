#include<stdio.h>
#include<stdlib.h>
void insert_to_index(int* arr, int index, int size,int new_data);
int main()
{
    int size;
    scanf("%d", &size);
    int index;
    scanf("%d", &index);
    int* arr = (int*)malloc(size * sizeof(int));
    for (int i = 0;i < size;i++)
    {
        scanf("%d", &arr[i]);
    }
    size = size + 1;
    arr = realloc(arr, size * sizeof(int));
    int new_data = 8;
    insert_to_index(arr, index, size,new_data);
}
void insert_to_index(int* arr, int index, int size,int new_data)
{
    for (int i = size-1;i > index;i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = new_data;
    for (int i = 0;i < size;i++)
    {
        printf("%d ", arr[i]);
    }

}