#include<stdio.h>
int is_perfect_square(int num);
int main()
{
    int num;
    printf("Enter the Number :");
    scanf("%d", &num);
    int ret = is_perfect_square(num);
    if (ret)
    {
        printf("Perfect Square\n");
    }
    else
    {
        printf("Not Perfect Square");
    }
    return 0;
}
int is_perfect_square(int num)
{
    if (num < 0)
    {
        return 0;
    }
    for (int i = 1;i * i <= num;i++)
    {
        if (i * i == num)
        {
            return 1;
        }
    }
    return 0;
}