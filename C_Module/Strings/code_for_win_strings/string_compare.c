#include <stdio.h>

int my_strcomp(char str1[], char str2[]);

int main()
{
    char str1[100], str2[100];
    scanf("%[^\n]", str1);
    getchar();
    scanf("%[^\n]", str2);

    if(my_strcomp(str1, str2) == 1)
        printf("Equal\n");
    else
        printf("Not equal\n");

    return 0;
}

int my_strcomp(char str1[], char str2[])
{
    int i = 0;

    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
            return 0;  // return immediately on mismatch
        i++;
    }

    // If both strings ended, they are equal
    if(str1[i] == '\0' && str2[i] == '\0')
        return 1;
    else
        return 0;  // lengths differ
}
