#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    int absolute= (num<0 ?-(num):num);
    printf("absolute value is %d\n",absolute);
    return 0;
}