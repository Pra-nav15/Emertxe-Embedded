#include<stdio.h>
int fact(int num)
{
int i,fact=1;
  for(i=num;i>=1;i--)
  {
    fact = fact * i ;
  }
  return fact;
}
int main()
{
    int num;
    scanf("%d",&num);
    int result = fact(num);
    printf("%d \n",result);
    return 0;
}