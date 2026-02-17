#include<stdio.h>
#include<stdlib.h>
int* merge_array(int* arr1, int n1, int* arr2, int n2, int* result, int n3);
int main()
{
    int n1, n2;
    printf("Enter the Array1 Size and Array2 Size :");
    scanf("%d %d", &n1, &n2);
    int* arr1 = (int*)malloc(n1 * sizeof(int));
    for (int i = 0;i < n1;i++)
    {
        scanf("%d", &arr1[i]);
    }
    int* arr2 = (int*)malloc(n2 * sizeof(int));
    for (int j = 0;j < n2;j++)
    {
        scanf("%d", &arr2[j]);
    }
    int n3 = n1 + n2;
    int* result = (int*)malloc(n3 * sizeof(int));
    merge_array(arr1,n1,arr2,n2,result,n3);
    for (int i = 0;i < n3;i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}
int* merge_array(int* arr1,int n1, int* arr2, int n2, int* result,int n3)
{
    int k = 0;
    for (int i = 0;i < n1;i++)
    {
        result[k++] = arr1[i];
    }
    for (int j = 0;j < n2;j++)
    {
        result[k++] = arr2[j];
    }
    return result;
}