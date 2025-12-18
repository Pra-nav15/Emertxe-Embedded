#include<stdio.h>
int main() {
    int n = 5, i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        printf("%d",i);
        if (i > 1)
        {
            for (j = 1; j <= 2 * (i - 1) - 1; j++)
            {
                printf(" ");
            }
            printf("%d", i);
        }
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--)
    {
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        printf("%d", i);
        if (i > 1)
        {
            for (j = 1; j <= 2 * (i - 1) - 1; j++)
            {
                printf(" ");
            }
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}
