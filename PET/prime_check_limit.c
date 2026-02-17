#include<stdio.h>
int prime_check(int, int);
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    prime_check(a, b);
    return 0;
}
int prime_check(int a, int b)
{
    int i, flag;
    for (i = a;i<=b;i++)
    {
        if (i < 2)
        {
            continue;
        }
        flag = 1;
        for (int j = 2;j*j <= i;j++)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            printf("%d ", i);
        }
    }
}