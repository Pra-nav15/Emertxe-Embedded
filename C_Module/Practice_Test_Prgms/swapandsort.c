#include<stdio.h>
int main(){
    int num,temp=0,rem,first,last,swap;
    printf("Enter a number: ");//read number from the user
    scanf("%d",&num);
      while(num>0)
      {
          rem=num%10;
          temp=temp*10+rem;
      }
      printf("%d",temp);// display reversed number
      return 0;
    }
    