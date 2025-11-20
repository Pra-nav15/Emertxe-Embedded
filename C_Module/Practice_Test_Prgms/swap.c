#include<stdio.h>
int main()
{
    int a,b,temp=0;
    printf("Enter 2 numbers a and b: ");
    scanf("%d %d",&a,&b);
    temp=a;
    a=b;
    b=temp;
    printf("a is %d and b is %d",a,b);
    return 0;
}