#include<stdio.h>
void find_lcm(int,int,int*);
void find_gcdorhcf(int,int,int*);
int main()
{
    int num1,num2;
    printf("Enter 2 numbers for lcm and gcd :");
    scanf("%d %d",&num1,&num2);
    int lcm=0,hcf=0;
    find_lcm(num1,num2,&lcm);
    printf("LCM is %d\n",lcm);
    find_gcdorhcf(num1,num2,&hcf);
    printf("HCF is %d",hcf);
}
void find_lcm(int num1,int num2,int* lcm)
{
    *lcm = num1 > num2 ? num1 : num2;
    while(1)
    {
        if((*lcm)%num1 == 0 && (*lcm)%num2 == 0)
        {
            break;
        }
        (*lcm)++;
    }
}
void find_gcdorhcf(int num1,int num2,int *hcf)
{
    int gcd = num1 < num2 ? num1 : num2;
    for(int i=1;i<=gcd;i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            *hcf = i;
        }
    }
}