#include<stdio.h>
int digit_sum(int num)
{
    if(num==0)
    {
        return 0;
    }
    else
    {
        return num%10+digit_sum(num/10);
    }
}
int main()
{
    int num,ret;
    scanf("%d",&num);
    ret=digit_sum(num);
    printf("%d",ret);
}