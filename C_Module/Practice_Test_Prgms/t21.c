#include<stdio.h>
int main(){
    int rev=0,rem=0,num;
    printf("The Number: ");
    scanf("%d",&num);
    while(num>0)
    {
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    printf("%d\n",rev);
    if(num==rev)
    {
      printf("Number is Palindrome\n");
    }
    else
    {
     printf("Number is not Palindrome\n");
    }
    return 0;
}