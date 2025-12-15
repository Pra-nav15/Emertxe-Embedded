#include<stdio.h>
int sumof_even_digits(int num);
int main()
{
    int num;
    scanf("%d", &num);
    int ret = sumof_even_digits(num);
    printf("Sum of even digits is : %d\n", ret);
    int result = ret;
    if (result > 9)
    {
        int count = 0;
        while (1)
        {
            if (result > 9)
            {
                result = result - 1;
                count++;
            }
            else
            {
                break;
            }
        }
        printf("Sum of even digits after reduction is  : %d\n", count-1);
    }
    else
    {
        printf("Sum of even digits after reduction is  : %d\n", result);
    }
    return 0;
}
int sumof_even_digits(int num)
{
    int rem = 0, sum = 0;
    while (num != 0)
    {
        rem = num % 10;
        if (rem % 2 == 0)
        {
            sum += rem;
        }
        num = num / 10;
    }
    if (sum == 0)
    {
        printf("No Even Digits in the Number\n");
        return 0;
    }
        return sum;
}