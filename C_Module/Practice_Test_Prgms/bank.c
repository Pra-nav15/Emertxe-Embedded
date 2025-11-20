#include<stdio.h>
int main()
{
    int w,d,n,current=0,x,balance=0;
    printf("1.Withdrwal    2.deposit: ");
    scanf("%d%d",&w,&d);
    if(d==2)
    {
        printf("Enter Deposit Amount:");
        scanf("%d",&n);
        current+=n;
        printf("%d is deposited in your account",current);
        balance+=current;
        printf("%d is balance in your account",balance);
    }
    else if(w==1)
    {
        printf("Enter Withdrwal Amount:");
        scanf("%d",&x);
        current=current-x;
        printf("%d is withdrawed from your account",current);
        balance-=current;
        printf("%d is balance in your account",balance);
    }
    else
    {
        printf("Exit");
    }
    return 0;
}