#include<stdio.h>
int is_prime(int);
void generate_prime(int);
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    generate_prime(n);
    return 0;
}
int is_prime(int i)
{
    for (int j = 2;j*j<=i;j++)
    {
        if (i % j == 0)
        {
            return 0;
        }
    }
    return 1;
}
void generate_prime(int n)
{
    printf("First %d prime numbers : ", n);
    int count = 0;
    for (int i = 2;count<n;i++)
    {
        if (is_prime(i) == 1)
        {
            count++;
            printf("%d ", i);
        }
    }
}