#include<stdio.h>
int main()
{
    int num = 0x12;
    int i,clear;
    for (i = 31;i >= 0;i--)
    {
        clear = (num & ~(1 << i));
        num = (clear | (num & (1 << (31 - i))));
    }
    printf("%x", num);
}