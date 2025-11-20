#include<stdio.h>  //processor directive
#define NUM 100 //macro
int x;

int foo()
{
    //printf function prints x value
    printf("x in fun %d\n",x);
    //return the value
    return ++x;


}

int main()
{
    //fun call
    foo();
    //conditional comp
 #if 1
    printf("x in main %d\n",x);
    printf("NUM in main %d\n",NUM);
 #endif 
    return 0;
    
}