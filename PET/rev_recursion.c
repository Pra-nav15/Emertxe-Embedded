#include<stdio.h>
int rev_recursion(int num,int rev);
int main()
{
    int num = 121345,rev=0;
    int ret =rev_recursion(num, rev);
    printf("%d", ret);
    return 0;
}
int rev_recursion(int num,int rev)
{
    if (num <= 0)
    {
        return rev;
    }
    rev_recursion(num / 10, rev * 10 + (num % 10));
}