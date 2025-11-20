#include<stdio.h>
int power(int n,int m)
{
    if(m==1)
    {
       return n;
    }
    else
    {
       return n*power(n,m-1);
    }
}
int main()
{
    int n,m,ret;
    scanf("%d %d",&n,&m);
    ret=power(n,m);
    printf("%d",ret);
}