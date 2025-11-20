#include<stdio.h>
char* my_strcases(char str[]);
int main()
{
    char str[100];
    scanf("%[^\n]",str);
    char* ret=my_strcases(str);
    printf("Case Converted String is %s",ret);
    return 0;
}
char* my_strcases(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
      if(str[i]>='a' && str[i]<='z')
      {
       str[i]=str[i]-32;
      }
       i++;
    }
    return str;
}