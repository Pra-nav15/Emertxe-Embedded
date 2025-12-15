#include<stdio.h>
void string_to_upper(char* str);
int main()
{
    char str[100] = "Hello, World!";
    string_to_upper(str);
    char str2[100] = "Have a great day ahead!";
    string_to_upper(str2);
    return 0;
}
void string_to_upper(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 97)
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
    printf("%s\n", str);
}