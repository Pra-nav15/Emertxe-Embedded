#include<stdio.h>

int main()
{
    unsigned int n = 0x12745643;

    unsigned int res = (((n >> 24) & 0X000000FF) || ((n >> 8) & 0x0000FF00) || ((n << 24) & 0x00FF0000) || ((n << 8) & 0xFF000000));
    printf("%u\n", res);

}