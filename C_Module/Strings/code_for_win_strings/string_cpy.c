#include<stdio.h>
char* my_strcopy(char str1[],char str2[]);
int main()
{
    char str1[100],str2[100];
    scanf("%[^\n]",str1);
    char* ret=my_strcopy(str1,str2);
    printf("Copied String is %s",ret);
    return 0;
}
char* my_strcopy(char str1[],char str2[])
{
    int i=0;
    while(str1[i]!='\0')
    {
       str2[i]=str1[i];
       i++;
    }
    return str2;
}