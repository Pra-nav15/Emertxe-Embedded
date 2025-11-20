#include<stdio.h>
int add(int num1, int num2);
int sub(int num1, int num2);
int oper(int (*f)(int, int), int a, int b); //func_name(file_pointer,arg1,arg2)
int main()
{
    int (*fptr)(int, int); //funcptr

    fptr = add;// address of add to fptr
    printf("add = %d\n", oper(fptr, 26, 4)); //call back fun
    fptr = sub;
    printf("sub = %d\n", oper(fptr, 12, 4));

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
int oper(int (*f)(int, int), int a, int b)
{
    return f(a, b);
}
