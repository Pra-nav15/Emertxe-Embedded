#include<stdio.h>
void fun(int*, int*,int*,float*);
int main()
{
    int a, b, sum = 0;
    float avg = 0;;
    a = 5;
    b = 9;
    fun(&a, &b, &sum, &avg);
    printf("Sum is %d\n", sum);
    printf("Average is %g\n", avg);
    return 0;
}
void fun(int* a, int* b, int* sum, float* avg)
{
    *sum = *a + *b;
    *avg = (float)*sum / 2;
}