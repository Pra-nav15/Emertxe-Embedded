#include <stdio.h>
#include <string.h>

void string_pattern(char *str, char *pattern);

int main()
{
    char str[100];
    char pattern[100];
    scanf(" %[^\n]", str);
    scanf("%s", pattern);
    string_pattern(str, pattern);
    return 0;
}

void string_pattern(char *str, char *pattern)
{
    char *words[100];
    int wcount = 0;
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        words[wcount++] = token;
        token = strtok(NULL, " ");
    }
    int plen = strlen(pattern);
    if (wcount != plen)
    {
        printf("Pattern does not match\n");
        return;
    }
    for (int i = 0; i < plen; i++)
    {
        for (int j = i + 1; j < plen; j++)
        {
            if ((pattern[i] == pattern[j] && strcmp(words[i], words[j]) != 0) || (pattern[i] != pattern[j] && strcmp(words[i], words[j]) == 0))
            {
                printf("Pattern does not match\n");
                return;
            }
        }
    }
    printf("Pattern matches\n");
}
