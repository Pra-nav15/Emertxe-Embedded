/* #include<stdio.h>
int fun(int);
int main()
{
    int res;
    res = fun(50);
    printf("%d\n", res);
}
int fun(int num)
{
    if (num <= 3)
    {
        return 1000;
    }
    else
    {
        fun(--num);
        printf("%d\n",num);
    }
} */
#include<stdio.h>
int fun(int);
int main()
{
    int res;
    res = fun(5);
    printf("%d\n", res);
}
int fun(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    else
    {
        return fun(num - 1) + fun(num - 2);
    }
}