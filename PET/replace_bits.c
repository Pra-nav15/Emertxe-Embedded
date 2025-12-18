#include<stdio.h>
int main()
{
    int num = 0x10;
    int value = 0x12;
    int bits = 3;
    num = (num & ~((1 << bits) - 1)) | (value & ((1 << bits) - 1));
    printf("%X", num);

}