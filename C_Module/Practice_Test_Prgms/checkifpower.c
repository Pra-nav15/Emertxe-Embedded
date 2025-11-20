#include<stdio.h>
int main()
{
    int num,result=1,i;   printf("Enter the number:");
    scanf("%d",&num);
    int temp=1;
    while(num%2==0)
    {
        temp=temp*2;
    }
    if(temp%2==0)
    {
        printf("Power of 2");
    }
    else
    {
        printf("Not power of 2");
    }
    

}