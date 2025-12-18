#include<stdio.h>
int main()
{
    int limit;
    scanf("%d", &limit);
    if (limit <= 0)
    {
        printf("Invalid Limit");
    }
    else
    {
        int i = 1, num = 1, sum = 0;
        while (i <= limit)
        {
            printf("%d ", num);
            sum += num;
            num = num + 2;
            i++;
        }
        printf("\nCount is %d\n", sum);
    }
}