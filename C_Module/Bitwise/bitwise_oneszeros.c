#include<stdio.h>
int main()
{
    int num,c1=0,c2=0;
    scanf("%d", &num);
    for (int i = 31;i >= 0;i--)
    {
        if (num & (1 << i))
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    printf("Total number of ones is %d and zeros is %d in the binary number %d\n", c1, c2, num);
}