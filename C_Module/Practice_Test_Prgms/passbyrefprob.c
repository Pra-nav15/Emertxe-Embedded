
#include<stdio.h>
int square(int arr[],int size);
int main()
{
    int size,i;
    printf("Enter the array size : ");
    scanf("%d",&size);
    int arr[size];;
    printf("Enter the array elements : ");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array elements before squaring : ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    square(arr,size);
}
int square(int arr[], int size)
{
    int i=0;
    printf("Array elements after squaring : ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]*arr[i]);
    }
}