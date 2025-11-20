#include<stdio.h>
int main()
{
    char ch,*ptr;
    printf("Enter the input : ");
    scanf("%c",&ch);
    *ptr=ch;
    printf("Character entered is %c\n",*ptr);
    
}