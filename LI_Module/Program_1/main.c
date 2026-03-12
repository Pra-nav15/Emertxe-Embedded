#include <stdio.h>
int add(int, int);
int substract(int, int);
int main()
{
    int result;
    result = add(5, 3);
    printf("%d\n", result);
    result = substract(5, 3);
    printf("%d\n", result);
    return 0;
}