#include<stdio.h>
int countDigits(int);
int main()
{
    int num;
    scanf("%d", &num);
    int ret = countDigits(num);
    printf("Number of Digits is: %d", ret);
    return 0;
}
int countDigits(int num)
{
    int count = 1;
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return count+countDigits(num / 10);
    }
}