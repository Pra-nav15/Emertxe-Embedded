#include<stdio.h>
int main()
{
    int i,j,n=4,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i==j)
             printf("%d ",j);
            else if(i==n)
            {
                for(k=10;k>4;k--)
                {
                    printf("%d ",k);
                    k=k-3;
                }
            }
            else if(i==n-1)
            {
                for(k=8;k>3;k--)
                {
                    printf("%d ",k);
                    k=k-3;
                }
            }
            else if(i==n-2)
            {
                for(k=5;k>2;k--)
                {
                    printf("%d ",k);
                    k=k-3;
                }
            }
            else
             printf("%d ",n-3);
            
        }
        printf("\n");
    }
}