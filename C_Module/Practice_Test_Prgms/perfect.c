/* #include<stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum==n)
    {
        printf("%d is a perfect number\n",n);
    }
    else
    {
        printf("%d is not a perfect number\n",n);
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    printf("Factors of %d is ",n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
            printf("%d ",sum);
        }
    }
    return 0;
} */
#include<stdio.h>
int main()
{
    int i,j,s,l,sum;
    scanf("%d %d",&s,&l);
    for(i=s;i<=l;i++)
    {
        sum=0;
        for(j=1;j<=i/2;j++)
        {
            if(i%j==0)
            {
                sum=sum+j;
            }
        }
        if(i==sum)
        {
            printf("%d ",i);
        }
    }
     return 0;
}