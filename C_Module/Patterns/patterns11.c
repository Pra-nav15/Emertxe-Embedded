
#include<stdio.h>
int main()
{
    int i, j, n = 7;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == 1 || i == n || j == 1 || j == n)
            {
                printf(" 4 ");
            }
            else if(i == 2 || i == n - 1 || j == 2 || j == n - 1)
            {
                printf(" 3 ");
            }
            else if(i == 3 || i == n - 2 || j == 3 || j == n - 2)
            {
                printf(" 2 ");
            }
            else
            {
                printf(" 1 ");
            }
        }
        printf("\n");
    }
}

