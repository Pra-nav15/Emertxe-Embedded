#include<stdio.h>
int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    int result= (num1>num2 ? num1:num2);
    printf("largest is %d\n",result);
    return 0;
}