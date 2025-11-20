#include <stdio.h>

int main()
{
    static int num;
    static int fact = 1;
    if(fact==1)
    {
        //printf("Enter the value of N :");
        scanf("%d",&num);
        if(num<0)
        {
            printf("Invalid Input\n");
            return 0;
        }
    }
    if(num==1 || num==0)
    {
        printf("Factorial of the given number is %d",fact);
        return 0;
    }
    fact=fact*num--;
    main();
}