#include<stdio.h>
void binary_convert(int num);
int reverse_num(int num, int rev);
int main()
{
    int num;
    scanf("%d", &num);
    binary_convert(num);
    int rev = 0;
    int ret = reverse_num(num, rev);
    printf("%d ", ret);
    return 0;
}
int reverse_num(int num,int rev)
{
    if (num == 0)
    {
        return rev;
    }
    reverse_num(num / 10, rev * 10 + (num % 10));
}
void binary_convert(int num)
{
    if (num <= 0)
    {
        return;
    }
    binary_convert(num / 2);
    printf("%d ", num % 2);
}