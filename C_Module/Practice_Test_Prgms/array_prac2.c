#include<stdio.h>
int main()
{
    int size=5,i,j,temp=0,prod=0;
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
        }
    }
    printf("Maximum product of a triplet (subsequence of size 3) in array is ");
    printf("%d * %d * %d = %d ",arr[size-1],arr[size-2],arr[size-3],arr[size-1]*arr[size-2]*arr[size-3]);

}