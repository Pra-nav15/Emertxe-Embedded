#include<stdio.h>
int main()
{
    unsigned int num;
    scanf("%x", &num);
    int count = 0;
    for (int i = 31;i >= 0;i--)
    {
        if (num & (1 << i))
        {
            count++;
        }
    }
    if ((count & 1) == 1)
    {
        printf("Bit Parity is Odd\n");
    }
    else
    {
        printf("Bit Parity is Even\n");
    }
}