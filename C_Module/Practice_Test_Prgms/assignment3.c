#include<stdio.h>
int main()
{
    int n,m;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter m: ");
    scanf("%d",&m);
    int x=(n-m)/2;
    if(n%2!=0 && m%2!=0)
    {
        for(int i=1;i<=x;i++)
        {
            printf("$");
        }
        for(int j=1;j<=m;j++)
        {
            printf("*");
        }
        for(int k=1;k<=x;k++)
        {
            printf("$");
        }
    }
    return 0;
}

    
