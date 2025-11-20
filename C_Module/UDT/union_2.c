#include<stdio.h>
union FloatBits
{
    float degree;
    struct
    {
        unsigned m : 23;
        unsigned e : 8;
        unsigned s : 1;
    }elements;
};
int main()
{
    union FloatBits num = { 3.2 }; //4 bytes will be allocated
    printf("float val : %f\n", num.degree); //access float value

    //Access bit fields
    printf("Sign : %#X\n", num.elements.s);
    printf("Exponent : %#X\n", num.elements.e);
    printf("Mantissa : %#X\n", num.elements.m);
    return 0;
}