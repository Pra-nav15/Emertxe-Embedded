#include<stdio.h>
int main(){
    int num1,num2,i,result=0;
    printf("Enter the two numbers: ");
    scanf("%d %d",&num1,&num2);
    for(int i=1;i<=num1;i++)
    {
       result=num1+i;
       result=result+num2;
    }
    printf("%d",result);
    return 0;
}