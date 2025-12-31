#include<stdio.h>
int countDigits(int);
int main()
{
    int num;
    scanf("%d", &num);
    int ret = countDigits(num);
    printf("Number of Digits is: %d", ret);
    return 0;
}
int countDigits(int num)
{
    if (num<=0)
    {
        return 0;
    }
    else
    {
        return 1 + countDigits(num / 10);
    }
}