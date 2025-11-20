#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the number of lines");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i+j>=n+1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for(j=2;j<=n;j++)
        {
            if(i>=j)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i=n-1;i>=1;i--)
    {
        for(j=1;j<=n;j++)
        {
            if(i+j>=n+1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for(j=2;j<=n;j++)
        {
            if(i>=j)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
