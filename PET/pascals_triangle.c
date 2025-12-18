#include<stdio.h>
int main()
{
    int i, j, val, k;
    for (i = 1;i <= 5;i++)
    {
        val = 1;
        for (k = 5;k > i;k--)
        {
            printf(" ");
        }
        for (j = 1;j <= i;j++)
        {
            printf("%d ", val);
            val = val * (i - j) / j;
        }
        printf("\n");
    }
}