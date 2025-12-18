#include<stdio.h>
int main()
{
    unsigned int num = 0xAF;
    for (int i = 31;i >= 0;i--)
    {
        int get = (num & (1 << i));
        num = ((num & ~(i << (31 - i))) | (get << i));
    }
    printf("%X", num);
    return 0;
}