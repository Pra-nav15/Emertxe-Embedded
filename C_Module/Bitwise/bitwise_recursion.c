#include<stdio.h>
int binary(unsigned int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        binary(num >> 1);
        printf("%d ", num & 1);
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    binary(num);
}