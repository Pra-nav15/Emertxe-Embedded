#include<stdio.h>
void rev_array(int arr[],int size);
void print_array(int arr[],int size);
int main()
{
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
      scanf("%d",&arr[i]);
    }
    rev_array(arr,size);
    print_array(arr,size);
}
void rev_array(int arr[],int size)
{
    if (size <= 1) 
    {
     return;
    }
    else 
    {
        int temp=0;
        temp=arr[0];
        arr[0]=arr[size-1];
        arr[size-1]=temp;
        rev_array(arr+1,size-2);
    }
}
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}