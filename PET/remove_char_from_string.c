#include<stdio.h>
void remove_char(char* str, char ch);
int main()
{
    char str[100];
    char ch;
    printf("Enter the String\n");
    scanf("%[^\n]", str);
    printf("Enter the Character\n");
    scanf(" %c", &ch);
    remove_char(str, ch);
    return 0;
}
void remove_char(char* str, char ch)
{
    int i = 0, len = 0, j = 0;
    while (str[i] != 0)
    {
        len++;
        i++;
    }
    while (str[j] != 0)
    {
        if (str[j] == ch)
        {
            for (int k = j;k < len ;k++)
            {
                str[k] = str[k + 1];
            }
            len--;
            j--;
        }
        j++;
    }
    str[len] = '\0';
    printf("%s", str);
}