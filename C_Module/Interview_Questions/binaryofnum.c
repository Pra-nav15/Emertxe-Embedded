#include<stdio.h>

void binary_convert(int num);

int main()
{
    int num;
    scanf("%d", &num);
    binary_convert(num);
}

void binary_convert(int num)
{
    if (num == 0)
    {
        return;
    }
    binary_convert(num / 2);
    printf("%d", num % 2);
}