
/* #include <stdio.h>

void positive_fibonacci(int limit, int first, int second, int result)
{
    if(first >= limit)
       return;

    printf("%d, ", result);
    result=first+second;
    positive_fibonacci(limit, second, result, result);
}

int main()
{
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    if(limit<0)
    {
        printf("Invalid input");
    }

    positive_fibonacci(limit, 0, 1, 0);

    return 0;
} */

/* 
#include <stdio.h>

void negative_fibonacci(int limit, int first, int second, int result)
{
    if(first <=limit)
       return;

    printf("%d ", first);
    result=first-second;
    negative_fibonacci(limit, second, result, result);
}

int main()
{
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    if(limit>0)
    {
        printf("Invalid input");
    }
    negative_fibonacci(limit, 0, 1, 0);

    return 0;
} */
