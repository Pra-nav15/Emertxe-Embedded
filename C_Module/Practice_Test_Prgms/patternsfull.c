/* #include<stdio.h>
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}  */
/* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}  */
/* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}  */
/* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=n;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}  */
/*  #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=n;i>=1;i--)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}  */
/*  #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for(i=2;i<=n;i++)
    {
        for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}  */
 /* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(k=n;k>=n-i+1;k--)
        {
            printf(" ");
        }
        for(j=1;j<=i;j++)
        {
            if(j==i || j==1 || i==n)
             printf("* ");
            else
             printf("  ");
        }
        printf("\n");
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       for(k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for(j=1;j<=2*i-1;j++)
        {
            if(j==i || i==n || i+j==n+1)
             printf("*");
            else
             printf(" ");
        }
        printf("\n");
    }
    return 0;
} */
/* #include<stdio.h>
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==i || i==n || i+j==n+1 || i==1)
             printf("*");
            else
             printf(" ");
        }
        printf("\n");
    }
    return 0;
} */
