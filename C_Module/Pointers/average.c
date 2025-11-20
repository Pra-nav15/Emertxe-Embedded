#include<stdio.h>
float avg(int* arr,int size)
{
    int sum=0,i;
    for(i=0;i<size;i++)
     sum+=*(arr+i);
    return (float)sum/size;
}
int main()
{
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the array elements : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Average is %g\n",avg(arr,size));
}