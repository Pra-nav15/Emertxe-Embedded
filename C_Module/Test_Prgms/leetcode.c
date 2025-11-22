#include<stdio.h>
int climbStairs(int);
int main()
{
    int  num = 4, ret;
    ret = climbStairs(num);
    printf("%d\n", ret);
}
int climbStairs(int n)
{
    if (n >= 1 && n <= 45)
    {
        int first = 1, second = 2, result = 0;
        if (n == 1)
        {
            result = 1;
        }
        else if (n == 2)
        {
            result = 2;
        }
        else
        {
            for (int i = 3; i <= n; i++)
            {
                result = first + second;
                first = second;
                second = result;
            }
        }
        return result;
    }
    return 0;
}
