/* #include<stdio.h>
void bin(int num);
int main()
{
    int num;
    scanf("%d",&num);
    bin(num);
}
void bin(int num)
{
    if(num==0)
    {
        return ;
    }
    else
    {
        int result=num%2;
        bin(num/2);
        printf("%d",result);
    }
} */
/* #include<stdio.h>
void oct(int num);
int main()
{
    int num;
    scanf("%d",&num);
    oct(num);
}
void oct(int num)
{
    if(num==0)
    {
        return ;
    }
    else
    {
        int result=num%8;
        oct(num/8);
        printf("%d",result);
    }
} */
#include<stdio.h>
void hex(int num);
int main()
{
    int num;
    scanf("%d",&num);
    hex(num);
}
void hex(int num)
{
    if(num==0)
    {
        return ;
    }
    else
    {
        int result=num%16;
        hex(num/16);
        printf("%x",result);
    }
}