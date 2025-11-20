
#include<stdio.h>
void main()
{
    char str[]= "welcome to jenny's lectures";
    char *ptr;
    ptr=str;
    printf("%c\n", *ptr);
    printf("ptr address=%u\n", ptr); 
    printf("%c\n", (ptr++ + 1)); 
    printf("ptr address =%u\n", ptr); 
    printf("%c\n",*((ptr-- +5)-1)+3); 
    printf("ptr address=%u\n", ptr); 
    printf("%c\n",*(++ptr +10)-32); 
    printf("%c %c %c\n", *ptr, *++ptr,*--ptr);
}