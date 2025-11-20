#include<stdio.h>
int main()
{
    int i,j,n,k;
    printf("Enter the number of lines:");
    scanf("%d",&n);
     for(i=n;i>=1;i--)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=2;i<=n;i++)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

            