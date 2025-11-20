#include<stdio.h>
int add(int num,int num1)
{
    return num + num1;
}
int main()
{
    int (*fptr)(int, int); //fun pointer
    fptr = add;
    printf("sum = %d\n", fptr(2, 4)); //fun call using ptr
    printf("sum = %d\n",(*fptr)(5,4));
    return 0;
}