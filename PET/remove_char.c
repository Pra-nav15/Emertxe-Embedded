#include<stdio.h>
#include<string.h>
void removeCharacter(char* str, char ch);
int main()
{
    char str1[] = "Hello World";
    removeCharacter(str1, 'o');

    char str2[] = "Pranav Prasad";
    removeCharacter(str2, 'a');
    return 0;
}
void removeCharacter(char* str, char ch)
{
    char result[100], k = 0, i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ch)
        {
            result[k++] = str[i];
        }
        i++;
    }
    result[k] = '\0';
    printf("%s\n", result);
}