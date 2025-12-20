#include<stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    char ch = 'A';
    for (int i = 1;i <= num;i++)
    {
        for (int k=num;k>i;k--)
        {
            printf(" ");
        }
        for (int j = 1;j <=2 * i-1;j++)
        {
            printf("%c", ch++);
        }
        printf("\n");
    }
    for (int i = num-1;i >= 1;i--)
    {
        for (int k=num;k>i;k--)
        {
            printf(" ");
        }
        for (int j = 1;j <=2 * i-1;j++)
        {
            printf("%c", ch--);
        }
        printf("\n");
    }
}