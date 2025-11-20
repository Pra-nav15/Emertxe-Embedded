#include<stdio.h>
int check(char str[],int *alpha,int *dig,int *spec);
int main()
{
    char str[100];
    int dig=0,alpha=0,spec=0;
    scanf("%[^\n]",str);
    check(str,&alpha,&dig,&spec);
    printf("Alphabets=%d\nDigits=%d\nSpecial Characters=%d\n",alpha,dig,spec);
    return 0;
}
int check(char str[],int *alpha,int *dig,int *spec)
{
    int i=0;
    while(str[i]!='\0')
    {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            (*alpha)++;
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            (*dig)++;
        }
        else
        {
           (*spec)++;
        }
        i++;
    }
    return *alpha,*dig,*spec;
}