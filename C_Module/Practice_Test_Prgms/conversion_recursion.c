/* #include<stdio.h>
void bin(int num)
{
    int result;
    if(num==0)
    {
        return ;
    }
    else
    {
        result=num%2;
        bin(num/2);
        printf("%d",result);
    }
}
int main()
{
    int num;
    scanf("%d",&num);
    bin(num);
    return 0;
} */
/* #include<stdio.h>
void hex(int num)
{
    int result;
    if(num==0)
    {
        return ;
    }
    else
    {
        result=num%16;
        hex(num/16);
        printf("%x ",result);
    }
}
int main()
{
    int num;
    scanf("%d",&num);
     hex(num);
    return 0;
} */
#include<stdio.h>
void oct(int num)
{
    int result;
    if(num==0)
    {
        return ;
    }
    else
    {
        result=num%8;
        oct(num/8);
        printf("%o ",result);
    }
}
int main()
{
    int num;
    scanf("%d",&num);
     oct(num);
    return 0;
} 