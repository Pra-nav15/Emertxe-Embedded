#include<stdio.h>
#define SECONDS_IN_YEAR(x) \
        (x * 365 * 60 * 60 * 24)
int main()
{
    int year;
    unsigned int long seconds;
    scanf("%d", &year);
    seconds = SECONDS_IN_YEAR(year);
    printf("%lu", seconds);
}