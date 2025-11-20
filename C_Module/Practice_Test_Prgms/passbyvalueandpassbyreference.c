/* // Pass by Value//
#include<stdio.h>
int add(int num1,int num2); // Function Declaration

int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    int result= add(num1, num2); // Function Call
    printf("Sum of two numbers is %d",result);
    
    return 0;
}
int add(int num1,int num2) // Function Definition
{
    return num1+num2; 
} */
// Pass by Refrence//
#include<stdio.h>
int add(int num1,int num2); // Function Declaration

int main()
{
    int num1,num2;
    scanf("%d",&num1);
    add(&num1); // Function Call
    printf("Sum of two numbers is %d",num1);
    
    return 0;
}
int add(int* ptr1) // Function Definition
{
    return *ptr1=*ptr+1; 
}
