#include<stdio.h>
void compare(char *str1,char *str2);
int main()
{
    char str1[100];
    char str2[100];
    printf("Enter the string1 : ");
    scanf("%[^\n]",str1);
    printf("Enter the string2 : ");
    scanf("%[^\n]",str2);
    compare(str1,str2);
}
void compare(char *str1,char *str2)
{
    while(*str1!=0 && *str2!=0)
    {
        if(*str1++ == *str2++)
        {
            printf("Entered Strings are equal");
        }
        else
        {
            printf("Entered Strings are not equal");
        }
    }
}