#include<stdio.h>
char* string_rev(char str[]);
int main()
{
    char str[100];
    scanf("%[^\n]",str);
    char* ret=string_rev(str);
    printf("Reverse of String is %s",ret);
    return 0;
}
char* string_rev(char str[])
{
   int i=0,start=0,len=0;
   while(str[i]!='\0')
   {
     len++;
     i++;
   }
   int end=len-1;
    while(start<end)
    {
        char temp;
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
   return str;
}