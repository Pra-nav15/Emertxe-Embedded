#include<stdio.h>
int second_largest_digit(int num);
int main()
{
    int num = 45861327;
    int ret = second_largest_digit(num);
    printf("Result is %d", ret);
    return 0;
}
int second_largest_digit(int num)
{
    int temp = num;
    int largest = 0;
    int sec_largest = 0;
    int smallest = 0;
    int rem = 0;
    while (temp != 0)
    {
        rem = temp % 10;
        if (rem > largest)
        {
            sec_largest = largest;
            largest = rem;
        }
        else if (rem < largest && rem > sec_largest)
        {
            sec_largest = rem;
        }
        temp /= 10;
    }
    return sec_largest;
}