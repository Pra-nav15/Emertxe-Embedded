/* #include<stdio.h>
int main()
{
    int num = 321;
    int rev = 0, rem = 0;
    while(num!=0)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    printf("%d", rev);
} */
#include<stdio.h>
int fun(int);
int main()
{
    int res = fun(123);
    printf("%d", res);
}
int fun(int num)
{
    static int rev = 0;
    if (num == 0)
    {
        return rev;
    }
    else
    {
        rev = rev * 10 + num % 10;
        fun(num / 10);
    }
}