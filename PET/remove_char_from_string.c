#include<stdio.h>
#include<string.h>
char* remove_char_from_string(char* str,char ch);
int main()
{
    char str[100],ch;
    printf("Enter the string : ");
    scanf("%[^\n]",str);
    printf("enter the Character to br removed : ");
    scanf(" %c",&ch);
    char* ret=remove_char_from_string(str,ch);
    printf("%s",ret);
    return 0;
}
char* remove_char_from_string(char* str,char ch)
{
    int i = 0, j = 0;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]!=ch)
        {
            str[j++]=str[i];
        }
    }
    str[j]='\0';
    return str;
}
