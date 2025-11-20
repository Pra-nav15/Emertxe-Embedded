#include<stdio.h>
int string_palindrome(char str[]);
int main()
{
    char str[100];
    scanf("%[^\n]",str);
    int ret=string_palindrome(str);
    if(ret==0)
    {
       printf("No\n");
    }
    else
    {
       printf("Yes\n");
    }
}
int string_palindrome(char str[])
{
    int i=0,len=0,start=0;
    while(str[i]!='\0')
    {
        len++;
        i++;
    }
    int end=len-1;
    while(start<end)
    {
        if(str[start]>='A' && str[start]<='Z')
        {
            str[start]+=32;
        }
        if(str[end]>='A' && str[end]<='Z')
        {
            str[end]+=32;
        }
        if(str[start]!=str[end])
        {
            return 0;
        }
        else
        {
            start++;
            end--;
        }
    }
    return 1;
}