#include<stdio.h>
#include<string.h>
char* replace_sequences(char *str);
int main()
{
    char str[]="bbcbbebbabfhbbahsobebebbc";
    char*ret=replace_sequences(str);
    printf("%s",ret);
    return 0;
}
char* replace_sequences(char* str)
{
    int i=0,k=0;
    while(str[i] != '\0')
    {
        if(str[i]=='b' && str[i+1]=='b' && str[i+2]=='c')
        {
            str[k++] = '$';
            i=i+3;
        }
        else if(str[i]=='b' && str[i+1]=='b' && str[i+2]=='e')
        {
            str[k++] = '&';
            i=i+3;
        }
        else if(str[i]=='b' && str[i+1]=='b')
        {
            str[k++] = '*';
            i=i+2;
        }
        else
        {
            str[k++] = str[i];
            i++;
        }
    }
    str[k] = '\0';
    return str;
}