#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    (num>0) ? printf("Positive Number\n"):(num<0) ? printf("Negative Number\n") : printf("Number is Zero\n");
    return 0;
}