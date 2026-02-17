#include<stdio.h>
int check_abundant(int num,int* sum);
int main()
{
    int num, sum = 0;
    printf("Enter the Number to be Checked: ");
    scanf("%d", &num);
    int ret = check_abundant(num,&sum);
    if (ret)
    {
        printf("Number is Abundant\n");
        printf("Abundance is %d\n", sum - num);
    }
    else
    {
        printf("Number is Not Abundant\n");
    }
    return 0;
}
int check_abundant(int num,int* sum)
{
    for (int i = 1;i < num;i++)
    {
        if (num % i == 0)
        {
            *sum += i;
        }
    }
    printf("Sum of Divisor is %d\n", *sum);
    if (*sum > num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}