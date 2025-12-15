#include <stdio.h>
#include <string.h>

int isVowel(char c)
{
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char str[100];
    int i = 0;
    int j;

    scanf("%s", str);
    j = strlen(str) - 1;

    while (i < j)
    {
        while (i < j && !isVowel(str[i]))
        {
            i++;
        }

        while (i < j && !isVowel(str[j]))
        {
            j--;
        }

        if (i < j)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }

    printf("%s", str);
    return 0;
}
