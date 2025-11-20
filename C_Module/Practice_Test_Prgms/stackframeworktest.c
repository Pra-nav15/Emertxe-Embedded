#include<stdio.h>
void fun(int x);

int main()
{
    int x=10;
    x=fun(x);
    printf("x = %d\n",x);
    return 0;
}

void fun(int x)
{
    ++x;
    return x;
}