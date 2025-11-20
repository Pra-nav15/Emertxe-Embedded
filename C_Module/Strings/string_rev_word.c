#include<stdio.h>
char* str_rev(char str[]);
void word_reverse(char str[],int start,int end);
int main()
{
    char str[100];
    //printf("Enter the string");
    scanf("%[^\n]",str);
    char* ret=str_rev(str);
    printf(" Reversed string:%s",ret);
}
char* str_rev(char str[])
{
    int i=0,j=0,start=0,end=0,len=0;
    while(str[i]!='\0')
    {
        len++;
        i++;
    }
    //word_reverse(str,0,len-1); include it to reverse each word in a string
    for(int j=0;j<=len;j++)
    {
        if(str[j]==' ' || str[j]=='\0')
        {
            end=j-1;
            word_reverse(str,start,end);
            start=j+1;
        }
    }
    return str;
}
void word_reverse(char str[],int start,int end)
{
    char temp;
    while(start<end)
    {
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
}