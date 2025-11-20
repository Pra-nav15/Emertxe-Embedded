#include<stdio.h>
int my_strlength(char str[]);
int main()
{
    char str[100];
    scanf("%[^\n]",str);
    int length=my_strlength(str);
    printf("String length is %d",length);
    return 0;
}
int my_strlength(char str[])
{
    int i=0,len=0;
    while(str[i]!='\0')
    {
       len++;
       i++;
    }
    return len;
}