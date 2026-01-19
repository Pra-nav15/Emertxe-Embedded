#include<stdio.h>
void largest_palindrome(int*, int*, int*);
int main()
{
    int a, b, pali = 0;
    printf("Enter the The Range : ");
    scanf("%d %d", &a, &b);
    largest_palindrome(&a, &b, &pali);
    printf("Largest Palindrome is %d", pali);
    return 0;
}
void largest_palindrome(int* a, int* b, int* pali)
{
    int temp, num;
    for (int i = *a;i <= *b;i++)
    {
        temp = i;
        num = i;
        int rev = 0, rem = 0;
        while (temp != 0)
        {
            rem = temp % 10;
            rev = rev * 10 + rem;
            temp /= 10;
        }
        if (rev == num)
        {
            *pali = rev;
        }
    }
    return;
}