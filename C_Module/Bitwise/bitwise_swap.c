#include<stdio.h>
int swap(unsigned int num)
{
    return ((num & 0x0F) << 4) | ((num & 0xF0) >> 4);
}
int main()
{
    unsigned int num;
    scanf("%X", &num);
    unsigned int ret = swap(num);
    printf("%X", ret);
}