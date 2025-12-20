#include<stdio.h>
#include<string.h>
void replaceSequences(char* str);
int main()
{
    char str[] = "bbcbbebb";
    replaceSequences(str);
}
void replaceSequences(char* str)
{
    int len = strlen(str);
    char temp[len], k = 0;
    for (int i = 0;i < len;i++)
    {
        if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == 'c')
        {
            temp[k++] = '$';
            i = i + 2;
        }
        else if (str[i] == 'b' && str[i + 1] == 'b' && str[i + 2] == 'e')
        {
            temp[k++] = '&';
            i = i + 2;
        }
        else if (str[i] == 'b' && str[i + 1] == 'b')
        {
            temp[k++] = '*';
            i = i + 2;
        }
        else
        {
            temp[k++] = str[i];
        }
    }
    temp[k] = '\0';
    printf("%s", temp);
}