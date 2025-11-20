#include<stdio.h>
int main()
{
    unsigned int num;
    int flag = 0;
    scanf("%X", &num);
    for (int i = 31;i >= 0;i--)
    {
        if ((num & (1 << i)) == (num & (1 << i-2)))
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("2's power");
    }
    else
    {
        printf("Not 2's power");
    }
}