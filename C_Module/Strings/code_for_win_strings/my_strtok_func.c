#include <stdio.h>

char *my_strtok(char str[], const char delim[]);

int main()
{
    char str[100], delim[50];

    scanf("%[^\n]", str);   // Read full line including spaces and special chars
    getchar();              // consume newline
    scanf("%s", delim);

    char *token = my_strtok(str, delim);
    printf("Tokens :\n");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }

    return 0;
}

char *my_strtok(char str[], const char delim[])
{
    static char *ptr;
    if (str != NULL)
        ptr = str;

    if (ptr == NULL)
        return NULL;

    // Skip leading delimiters
    while (*ptr != '\0')
    {
        int is_delim = 0;
        for (int j = 0; delim[j] != '\0'; j++)
        {
            if (*ptr == delim[j])
            {
                ptr++;
                is_delim = 1;
                break;
            }
        }
        if (!is_delim)
            break;
    }

    if (*ptr == '\0')
        return NULL;

    char *start = ptr;

    // Move until next delimiter or end
    while (*ptr != '\0')
    {
        for (int j = 0; delim[j] != '\0'; j++)
        {
            if (*ptr == delim[j])
            {
                *ptr = '\0';
                ptr++;
                return start;
            }
        }
        ptr++;
    }

    return start;  // last token
}
