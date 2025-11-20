#include<stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    for (int i = 7;i >= 0;i--)
    {
        if (num & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}