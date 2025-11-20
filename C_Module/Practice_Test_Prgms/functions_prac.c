/* #include<stdio.h>
float average(int num1,int num2,int num3);
int main()
{
    int num1,num2,num3;
    scanf("%d %d %d",&num1,&num2,&num3);
    float avg=average(num1,num2,num3);
    printf("%f ",avg);
}
float average(int num1,int num2,int num3)
{
   int sum=num1+num2+num3;
   return (float)sum/3;
} */
/* #include<stdio.h>
int sum_of_digits(int num);
int main()
{
    int num;
    scanf("%d",&num);
    float sum=sum_of_digits(num);
    printf("%d ",sum);
}
int sum_of_digits(int num)
{
   if(num==0)
   {
     return 0;
   }
   return (num%10)+sum_of_digits(num/10);
} */
/* #include<stdio.h>
int is_prime(int num);
int main()
{
    int num;
    scanf("%d",&num);
    int ret=is_prime(num);
    if(ret)
    {
        printf("Prime");
    }
    else
    {
        printf("Not Prime");
    }
    
}
int is_prime(int num)
{
   int i;
   for(i=2;i*i<=num;i++)
   {
    if(num%i==0)
      return 0;
   }
   return 1;
} */
/* #include<stdio.h>
int power(int a,int b);
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int ret=power(a,b);
    printf("%d",ret);
}
int power(int a,int b)
{
    int i,result=0;
    for(i=0;i<b;i++)
    {
        result+=a;
    }
    return result;
} */
/* #include<stdio.h>
int is_prime(int num);
void prime_series(int num);
int main()
{
    int num;
    scanf("%d",&num);
    is_prime(num);
    printf("Prime series:");
    prime_series(num);
}
int is_prime(int num)
{
   int i;
   for(i=2;i*i<=num;i++)
   {
    if(num%i==0)
      return 0;
   }
   return 1;
} 
void prime_series(int num)
{
    int i;
    for(i=2;i<num;i++)
    {
        if(is_prime(i))
        {
           printf("%d ",i);
        }
    }
} */
#include<stdio.h>
int fibo(num);
int main()
{
  int num;
  scanf("%d",&num);
}