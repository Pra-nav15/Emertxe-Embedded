#include<stdio.h>
char* my_strconcat(char str1[],char str2[]);
int main()
{
    char str1[100],str2[100];
    scanf("%[^\n]",str1);
    getchar();
    scanf("%[^\n]",str2);
    char* ret=my_strconcat(str1,str2);
    printf("%s",ret);
}
char* my_strconcat(char str1[],char str2[])
{
    int i=0,j=0,len=0,len2=0;
    while(str1[i]!='\0')
    {
        len++;
        i++;
    }
     while(str2[j]!='\0')
    {
        len2++;
        j++;
    }
    for(int i=0;i<len2;i++)
    {
        str1[len+i]=str2[i];
    }
    str1[len+len2]='\0';
    return str1;
}