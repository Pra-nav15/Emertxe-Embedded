#include<stdio.h>
struct Circle {
    float radius;
};
struct Circle c1, c2;
void check(float radius, float* area, float* peri);
int main()
{
    struct Circle *ptr1 = &c1;
    struct Circle *ptr2 = &c2;
    ptr1->radius = 5;
    ptr2->radius = 10;
    float area = 0, peri = 0;
    check(ptr1->radius, &area, &peri);
    printf("Circle 1: Area is %g and Perimeter is %g\n", area, peri);
    check(ptr2->radius, &area, &peri);
    printf("Circle 2: Area is %g and Perimeter is %g\n", area, peri);
    return 0;
}
void check(float radius, float *area, float *peri)
{
    *area = 3.14 * (radius) * (radius);
    *peri = 2 * 3.14 * (radius);
}