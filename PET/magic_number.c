#include<stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int sum = 0;
    while (num > 9)
    {
        sum = 0;
        while (num != 0)
        {
            sum += (num % 10);
            num = num / 10;
        }
        num = sum;
    }
    if (num == 1)
    {
        printf("Magic Number\n");
    }
    else
    {
        printf("Not Magic Number\n");
    }
    return 0;
}