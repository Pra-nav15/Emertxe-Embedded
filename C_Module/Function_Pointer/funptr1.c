#include<stdio.h>
int add(int num,int num1)
{
    return num + num1;
}
int main()
{
    int (*fptr)(int, int); //fun pointer
    fptr = add;
    printf("Address of add = %p\n", add);
    printf("fptr=%p\n", fptr);
    printf("fptr addr =%p\n", &fptr);
    return 0;
}