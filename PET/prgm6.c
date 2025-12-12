#include<stdio.h>
int natural_numbers(int);
int main()
{
    int num=10;
    natural_numbers(num);
    return 0;
}
int natural_numbers(int num)
{
    if (num<0)
    {
        return 0;
    }
    else
    {
        natural_numbers(num - 1);
        printf("%d ", num);
        return 0;
    }
}