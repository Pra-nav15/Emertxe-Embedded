#include<stdio.h>
int main()
{
    const int num=100;
    printf("%d\n",num);

    //num=150 ; // not allowed since num is const

    //modifying possible using pointers

   int *iptr= &num;
    *iptr=200; // possible 
    printf("%d\n",num);

    //showing address
    printf("%p\n",&num);
    printf("%p\n",&iptr);
}