#include <stdio.h>

int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);
int oper(int (*f)(int, int), int a, int b);

int main()
{
    int (*fptr[])(int, int) = {add, sub, mul, div};

    printf("add = %d\n", oper(fptr[0], 12, 4));
    printf("sub = %d\n", oper(fptr[1], 12, 4));
    printf("mul = %d\n", oper(fptr[2], 12, 4));
    printf("div = %d\n", oper(fptr[3], 12, 4));

    return 0;
}

int add(int num1, int num2)
{
    return num1 + num2;
}
int sub(int num1, int num2)
{
    return num1 - num2;
}
int mul(int num1, int num2)
{
    return num1 * num2;
}
int div(int num1, int num2)
{
    return num1 / num2;
}

int oper(int (*f)(int, int), int a, int b)
{
    return f(a, b);
}