#include<stdio.h>
int is_automorphic(int);
int main()
{
    int num, ret;
    printf("Enter the Number :");
    scanf("%d", &num);
    if (is_automorphic(num))
    {
        printf("It is Automorphic Number");
    }
    else
    {
        printf("Not Automorphic Number");
    }
    return 0;
}
int is_automorphic(int num)
{
    int flag;
    int temp = num;
    int temp1 = num * num;
    while (temp != 0)
    {
        if (temp % 10 != temp1 % 10)
        {
            return 0;
        }
        else
        {
            temp /= 10;
            temp1 /= 10;
        }
    }
    return 1;
}