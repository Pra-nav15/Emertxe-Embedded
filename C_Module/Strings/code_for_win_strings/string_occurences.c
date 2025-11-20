#include<stdio.h>
int character_occurences(char str[],const char *ch,int *count);
int main()
{
    char str[100],ch;
    int count=0;
    scanf("%[^\n]",str);
    getchar();
    scanf("%c",&ch);
    character_occurences(str,&ch,&count);
    printf("Occurence of character %c is %d",ch,count);
    return 0;
}
int character_occurences(char str[],const char *ch,int *count)
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]==(*ch))
        {
            (*count)++;
        }
        i++;
    }
    return *count;
}