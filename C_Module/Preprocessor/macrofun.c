#include<stdio.h>
#define SUM(a,b) (a+b)
#define DIFF(a,b) (a-b)
int main()
{
    int a = 512, b = -2;
    printf("%d\n", SUM(a, b));
    printf("%d\n", DIFF(a, b));
}