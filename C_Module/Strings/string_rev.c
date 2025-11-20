#include<stdio.h>
char* str_rev(char str1[],char temp);
int main()
{
    char str1[100];
    char temp;
    scanf("%[^\n]",str1);
    char* ret=str_rev(str1,temp);
    printf("%s",ret);
}
char* str_rev(char str1[],char temp)
{
    int i=0,j=0,length=0;
    while(str1[i]!='\0')
    {
        length++;
        i++;
    }
    while(j<length/2)
    {
        temp=str1[j];
        str1[j]=str1[length-j-1];
        str1[length-j-1]=temp;
        j++;
    }
    str1[length]='\0';
    return str1;
}