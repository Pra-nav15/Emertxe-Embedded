#include<stdio.h>
int main()
{
    unsigned int num = 0xAF;
    for (int i = 16;i <=31 ;i++)
    {
        int get1 = (num >> i) & 1;
        int get2 = (num >> (31 - i)) & 1;
        if (get1 != get2)
        {
            num ^= (1<<i);
            num ^= (1 << (31-i));
        }
    }
    printf("%x", num);
    return 0;
}