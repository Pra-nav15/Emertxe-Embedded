#include<stdio.h>
#if 1
#define ADD(x,y) (x+y)
#define SUB(x,y) (x-y)
#define MUL(x,y) (x*y)
#define DIV(x,y) (x/y)
#define MIN(x,y) x<y ? x:y
#define MAX(x,y) x>y ? x:y
#define SQUARE(x) (x*x)
#define CUBE(x) (x*x*x)
int main()
{
    int a, b,num;
    printf("Read 2 numbers : ");
    scanf("%d %d", &a, &b);
    printf("Sum is %d\n", ADD(a, b));
    printf("Difference is %d\n",SUB(a, b));
    printf("Product is %d\n",MUL(a, b));
    printf("Quotient is %d\n", DIV(a, b));
    printf("MIN is %d\n", MIN(a, b));
    printf("MAX is %d\n", MAX(a, b));
    printf("Read a number to find Square and Cube : ");
    scanf("%d", &num);
    printf("MIN is %d\n", SQUARE(num));
    printf("MAX is %d\n", CUBE(num));
    return 0;
}
#endif

