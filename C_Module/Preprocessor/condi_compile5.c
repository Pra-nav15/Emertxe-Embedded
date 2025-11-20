#include<stdio.h>
#define SPACE_OPTIMIZED
#define TIME_OPTIMIZED

int main()
{
    int x = 10, y = 20;
#if defined SPACE_OPTIMIZED
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
#else
    int temp;
    temp = x;
    x = y;
    y = temp;
#endif
    printf("")
    return 0;
}