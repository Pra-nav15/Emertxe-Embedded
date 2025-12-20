#include<stdio.h>
int main()
{
    int num = 548833, rem = 0, rev = 0, sum = 0;
    if (num < 0 && num == 0)
    {
        printf("Invalid");
    }
    int orginal = num;
    int temp = num;
    int count = 0;
    while (temp != 0)
    {
        count++;
        temp = temp/10;
    }
    while (num != 0)
    {
        rem = num % 10;
        int n = 1;
        for (int i = 1;i <= count;i++)
        {
            n *= rem;
        }
        sum += n;
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