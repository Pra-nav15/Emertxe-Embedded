#include<stdio.h>
int main()
{
    int size=5,flag=0,i;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size/2;i++)
    {
        if(arr[size-i-1]!=arr[i])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        printf("It is Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
}