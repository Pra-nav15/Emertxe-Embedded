#include<stdio.h>
int main()
{
    unsigned int num;
    int count = 0;
    scanf("%X", &num);
    for (int i = 31;i >= 0;i--)
    {
        if ((num & (1 << i)) != (num & (1 << (i - 1))))
        {
            count++;
        }
    }
    printf("Total number of flips is %d", count);
}