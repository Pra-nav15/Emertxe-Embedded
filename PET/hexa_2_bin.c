#include<stdio.h>
int main()
{
    unsigned int num = 0xAF;
    for (int i = 31;i >= 0;i--)
    {
        if (num & (1<<i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}