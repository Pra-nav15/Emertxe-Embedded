#include<stdio.h>
/*The Volatile keyword prevents the compiler from performing optimizations on code involving volatile objects
,thus ensuring that each volatile variable assignment and read has a corresponding memory access*/
int main()
{
    int num;
    //unsigned int i;
    volatile unsigned int i;

    for (int i = 0;i <0xFFFFFFFF;i++)
    {
        num = 5;
    }
    printf("%d\n", num);
    return 0;
}