/* 
#include <stdio.h>
int main()
{
    int i, j = 1;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            if (i == 1 || i == 5)
            {
                printf(" * ");
            }
            else if (i + j - 1 == 5)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}  */


/* #include <stdio.h>
int main()
{
    int i, j = 1;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            if (i == 1 || i == 5 || j==1)
            {
                printf(" * ");
            }
            else if (i>=3 && j==5 || (i>=3 && i!=4) && j==4)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
} */
#include <stdio.h>
int main()
{
    int i, j = 1;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            if (i == 1 || i == 5)
            {
                printf(" * ");
            }
            else if (j==1)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("  ");
        for (j = 1; j <= 5; j++)
        {
            if (i == 1 || j == 5 || j==1)
            {
                printf(" * ");
            }
            else if (i==3)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("  ");
        for (j = 1; j <= 5; j++)
        {
            if (i == 1)
            {
                printf(" * ");
            }
            else if (j==3)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
} 