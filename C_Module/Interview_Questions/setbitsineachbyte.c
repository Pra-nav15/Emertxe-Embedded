#include<stdio.h>

int main()
{
    unsigned int num;
    scanf("%u", &num);
    for (int i = 0;i < 4;i++)
    {
        unsigned char byte = (num >> (i * 8)) & 0xFF;
        int count = 0;
        while (byte)
        {
            count += byte & 1;
            byte = byte >> 1;
        }
    }
}