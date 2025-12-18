#include<stdio.h>
int main()
{
    int num = 54748, rem = 0, rev = 0, sum = 0;
    if (num < 0 && num == 0)
    {
        printf("Invalid");
    }
    int orginal = num;
    while (num != 0)
    {
        rem = num % 10;
        sum += (rem * rem * rem);
        num = num / 10;
    }
    if (sum == orginal)
    {
        printf("%d is Amstrong Number", orginal);
    }
    else
    {
        printf("%d is not an Amstrong Number", orginal);
    }
}