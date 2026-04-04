#include<stdio.h>
int profit_calculation(int n);
int* selling_order(int size, int* arr, int total_profit,int* ret_arr);
int main()
{
    int size, size1;
    printf("Size of plant array: ");
    scanf("%d",&size);
    int arr[size];
    int ret_arr[size1];
    printf("Plant Profit Values : ");
    for (int i = 0;i < size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Size of query array: ");
    scanf("%d",&size1);
    int arr1[size1];
    printf("Query Values : ");
    for (int i = 0;i < size1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    int total_profit = 0;
    for (int i = 0;i < size;i++)
    {
        total_profit += profit_calculation(arr[i]);
    }
    printf("Total Profit is %d\n", total_profit);
    selling_order(size1, arr1, total_profit, ret_arr);
    for (int i = 0;i < size1;i++)
    {
        printf("%d ", ret_arr[i]);
    }
    return 0;
}
int profit_calculation(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + profit_calculation(n / 2);
}

int* selling_order(int size1,int* arr1,int total_profit,int* ret_arr)
{
    for (int i = 0;i < size1;i++)
    {
        if (total_profit >= arr1[i])
        {
            ret_arr[i] = 1;
        }
        else
        {
            ret_arr[i] = 0;
        }
    }
    return ret_arr;
}