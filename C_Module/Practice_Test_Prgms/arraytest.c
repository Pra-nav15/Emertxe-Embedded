/* #include<stdio.h>
int main()
{
    int i,j,n,temp=0;
    scanf("%d",&n);
    int arr[n],sorted_arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
    }
    for(i=0;i<n;i++)
    {
        sorted_arr[i]=arr[i];
        printf("%d ",sorted_arr[i]);
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int i,j,n,temp=0;
    scanf("%d",&n);
    int arr[n],sorted_arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
    }
    for(i=n-1;i>=0;i--)
    {
        sorted_arr[i]=arr[i];
        printf("%d ",sorted_arr[i]);
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int i,j,n,temp=0,flag;
    scanf("%d",&n);
    int arr[n],sorted_arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=i+1;j<n;j++)
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
    int i,j,n,even=0,odd=0,zero=0;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i] %2  == 0 && arr[i]!=0)
        {
            even++;
        }
        else if(arr[i] %2 != 0)
        {
            odd++;
        }
        else
        {
            zero++;
        }
    }
    printf("Even = %d\n",even);
    printf("Odd = %d\n",odd);
    printf("Zero Occurences = %d\n",zero);
    return 0;
} */
/*  #include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    int arr[n],even_arr[n],odd_arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
       
       if(arr[i]%2==0)
       {
        even_arr[i]=arr[i];
        printf("%d ",even_arr[i]);
       } 
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
       if(arr[i]%2!=0)
       {
        odd_arr[i]=arr[i];
        printf("%d ",odd_arr[i]);
       } 
    }
    return 0;
} */
#include<stdio.h>
int main()
{
    int i,j,n,ele,flag;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&ele);
    for(i=0;i<n;i++)
    {
        if(ele==arr[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Element is present in array\n");
    }
    else
    {
       printf("Element is not present in array\n");
    }
    return 0;
   
}