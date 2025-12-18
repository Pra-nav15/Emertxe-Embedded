/* #include<stdio.h>
int main()
{
    int i, j, k, n = 5;
    for (i = 1;i <= n;i++)
    {
        for (k = n;k >= i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <= i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    for (i = n-1;i >= 1;i--)
    {
        for (k = i;k <= n;k++)
        {
            printf(" ");
        }
        for (j = 1;j <= i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
} */
#include<stdio.h>
/* int main()
{
    int i, j;
    for (i = 5;i >= 1;i--)
    {
        for (j = 5;j >= i;j--)
        {
            printf("%c ", j+64);
        }
        printf("\n");
    }

} */
/* int main()
{
    int i, j, count = 1;
    for (i = 1;i <= 5;i++)
    {
        for (j = 1;j<=i;j++)
        {
            printf("%c ", count + 64);
            count++;
        }
        printf("\n");
    }

} */
/* int main()
{
    int i, j, count = 1, n = 10;
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= n;j++)
        {
            if (i == 1 || i == n || j == 1 || j == n || j == i || j == n -i)
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
} *//* 
int main()
{
    int i, j, count = 1, n = 5;
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= n;j++)
        {
            if (i == 1 || i == n || j == 1 || j == n || j == i || j == (n+1) -i)
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
} */

/* int main()
{
    int i, j, k;
    for (i = 5;i >= 1;i--)
    {
        for (k = 5;k > i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <=(2*i-1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (i = 2;i <= 5;i++)
    {
        for (k = 5;k > i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <=(2*i-1);j++)
        {
            printf("*");
        }
        printf("\n");
    }
}/*  */
/* int main()
{
    int i, j, k;
    for (i = 5;i >= 1;i--)
    {
        for (k = 5;k > i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <=(2*i-1);j++)
        {
            if (j == 1 || j == (2*i - 1) || i == 5)
                printf("*");
            else
                printf(" ");

        }
        printf("\n");
    }
    for (i = 2;i <= 5;i++)
    {
        for (k = 5;k > i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <=(2*i-1);j++)
        {
            if (j == 1 || j == (2*i - 1) || i == 5)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}  */
 /* int main()
{
    int i, j, k;
    for (i = 5;i >= 1;i--)
    {
        for (k = 5;k > i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <=(2*i-1);j++)
        {
            printf(" ");
        }
         for (k = 5;k > i;k--)
        {
            printf("*");
        }
        printf("\n");
    }
    for (i = 2;i <= 5;i++)
    {
        for (k = 5;k > i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <=(2*i-1);j++)
        {
            printf(" ");
        }
        for (k = 5;k > i;k--)
        {
            printf("*");
        }
        printf("\n");
    }
}  */
/* int main()
{
    int i, j=1, count, n = 4;
    for (i = 1;i <= n;i++)
    {
        count = j;
        for (j = 1;j <= i;j++)
        {
            printf("%d\t", count++);
        }
        printf("\n");
    }
} */
int main()
{
    int i, j, count, n = 4;
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= i;j++)
        {
            if (j == 1)
            {
                count = i;
            }
            else
            {
                count = count + (n - j + 1);
            }
            printf("%d\t", count);
        }
        printf("\n");
    }
}