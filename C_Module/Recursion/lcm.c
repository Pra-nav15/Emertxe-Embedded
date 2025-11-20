#include <stdio.h>

int lcm(int a,int b,int num) 
{
    if(num%a==0 && num%b==0)
     return num;
    else
     return lcm(a,b,num+1);
}
int main() {
    int a,b,num;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        num=a;
    }
    else
    {
        num=b;
    }
    printf("LCM is %d",lcm(a,b,num));
    return 0;
}
