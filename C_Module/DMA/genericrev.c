#include<stdio.h>
void reverse(void* ptr, int size);
int main()
{
    int num = 0x12345678;
    reverse(&num,sizeof(num));
    printf("After reverse %#X\n", num);
    return 0;
}
void reverse(void* ptr, int size)
{
    char temp;
    for (int i = 0;i < size / 2;i++)
    {
        temp = *((char*)ptr + i);
        *((char*)ptr + i) = *((char*)ptr + (size - 1) - i);
        *((char*)ptr + (size - 1) - i) = temp;
        return;
    }
}