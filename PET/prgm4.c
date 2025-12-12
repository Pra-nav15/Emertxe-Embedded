#include<stdio.h>
void print_prime_palindrome(int num);
int prime_check(int num);
int main()
{
    int num;
    scanf("%d", &num);
    print_prime_palindrome(num);
    return 0;
}
int prime_check(int num)
{
    for (int i = 2;i < num;i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void print_prime_palindrome(int num)
{
    int i;
    for (i = 2;i < num;i++)
    {
        if (prime_check(i))
        {
            int j = i,rev = 0, rem = 0;
            while (j != 0)
            {
                rem = j % 10;
                rev = rev * 10 + rem;
                j = j / 10;
            }
            if (i == rev)
            {
                printf("%d ", i);
            }
        }
    }
}