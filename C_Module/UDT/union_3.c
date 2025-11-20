#include<stdio.h>
union Test
{
   int a;
   char b;
   float c;
};
int main()
{
    union Test u;
    u.a = 30;
    u.b = 'p';
    u.c = 78.90; //latest value allocated to the memory
    printf("%d \n", u.a);
    printf("%c \n", u.b);
    printf("%f \n", u.c);
    //always print last updated value which is 78.90 since it share same memory
}