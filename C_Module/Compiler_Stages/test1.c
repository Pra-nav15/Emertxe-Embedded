#include<stdio.h>
int foo();//fun declaration
int x=10; //global variable definition
int main()
{
    foo();//fun call
    printf("x in main %d\n", x);
    return 0;
}