#include<stdio.h>
int sumofn(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n+sumofn(n-1);
    }
}
int main()
{
    int n,ret;
    printf("Enter the limit: ");
    scanf("%d",&n);
    ret=sumofn(n);
    printf("Sum of n numbers is %d \n",ret);
}