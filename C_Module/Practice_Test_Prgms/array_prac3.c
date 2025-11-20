#include<stdio.h>
int main()
{
    int size=5,i,j,temp=0,d;
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before Rotation\n");
    for(i=0;i<size;i++)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter no of times to  rotate array: \n");
    scanf("%d",&d);
    printf("Rotated array %d times \n",d);
    for(i=d;i<size;i++)
    {
      printf("%d ",arr[i]);
    }
    for(i=0;i<d;i++)
    {
      printf("%d ",arr[i]);
    }
}