#include<stdio.h>
unsigned int bit_reversal(unsigned int);
int main()
{
    unsigned int num;
    scanf("%X", &num);
    unsigned int ret = bit_reversal(num);
    printf("The reversed bit is %#X", ret);
    return 0;
}
unsigned int bit_reversal(unsigned int num)
{
    for (int i = 31;i > 15;i--)
    {
        int bit1 = ((num >> i) & 1);
        int bit2 = ((num >> (31 - i)) & 1);
        if (bit1 != bit2)
        {
            num = num ^ (1U << i);
            num = num ^ (1U << (31 - i));
        }
    }
    return num;
}