#include<stdio.h>
char* str_concat(char str1[],char str2[]);
int main()
{
    char str1[100],str2[100];
    printf("String1:");
    scanf("%[^\n]",str1);
    getchar();
    printf("String2:");
    scanf("%[^\n]",str2);
    char* ret=str_concat(str1,str2);
    printf("%s",ret);
}
char* str_concat(char str1[],char str2[])
{
    int i=0,j=0,length1=0,length2=0;
    while(str1[i]!='\0')
    {
        length1++;
        i++;
    }
    while(str2[j]!='\0')
    {
        length2++;
        j++;
    }
    for(int i=0;i<=length2;i++)
    {
       str1[length1+i]=str2[i];
    }
     str1[length1+length2]='\0';
     return str1;
}