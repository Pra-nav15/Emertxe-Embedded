#include<stdio.h>
int main()
{
    int num=1;
    for(num;num<=100;num++)
    {
        if(num%3==0 && num%5==0)
        {
            printf("FizzBuzz ");
        }
        else if(num%3==0)
        {
            printf("Fizz ");
        }
        else if(num%5==0)
        {
            printf("Buzz ");
        }
        else
        {
            printf("%d ",num);
        }
        printf("\n");
    }
    return 0;
}

   