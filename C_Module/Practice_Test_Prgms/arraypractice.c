/* #include<stdio.h>
int main()
{
    int size,i;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Orginal Array elements: ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Reverse Array elements: ");
    for(i=size-1;i>=0;i--)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
} */
/* #include<stdio.h>
int main()
{
    int size,i,temp=0,j;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted Array elements: ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
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
    printf("Sorted Array elements: ");
    for(i=0;i<size;i++)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
} */
/*  #include<stdio.h>
int main()
{
    int size,i,temp=0,j;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array elements: ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
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
    printf("Largest Array element: ");
    printf("%d",arr[size-1]);
    printf("\n");
    printf("Second Largest Array element: ");
    printf("%d",arr[size-2]);
    printf("\n");
} */
/*  #include<stdio.h>
int main()
{
    int size,i,flag=0,j,k=0;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array elements: ");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Unique Array elements: ");
    for(i=0;i<size;i++)
    {
        flag=0;
        for(j=0;j<size;j++)
        {
            if(arr[i]==arr[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("%d ",arr[i]);
        }
    }
   return 0;
} */
/* #include<stdio.h>
int main()
{
    int size=5,i;
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Removed Zeros: ");
    for(i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
         printf("%d ",arr[i]);
        }
    }
} */
/* #include<stdio.h>
int main()
{
    int size=5,i;
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Toggle Zeros to ones: ");
    for(i=0;i<size;i++)
    {
        if(arr[i]==0)
        {
          arr[i]=1;
        }
        printf("%d ",arr[i]);
    }
} */
#include<stdio.h>
int main()
{
    int size=5,i,count=0;
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Max Consequtive 1's in an array: ");
    for(i=0;i<size;i++)
    {
        if(arr[i]==1)
        {
          count++;
        }
    }
    if(count>0)
    {
     printf("%d ",count);
    }
    else
    {
        printf("No consequtive 1's in given array");
    }
}