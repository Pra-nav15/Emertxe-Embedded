#include <stdio.h>

int main()
{
    char first_str[100], second_str[100], result[200];
    int i = 0, j = 0, k = 0;

    printf("Enter the first string:\n");
    scanf("%[^\n]", first_str);

    printf("Enter the second string:\n");
    scanf(" %[^\n]", second_str);

    while (first_str[i] || second_str[j])
    {
        if (first_str[i])
            result[k++] = first_str[i++];

        if (second_str[j])
            result[k++] = second_str[j++];
    }

    result[k] = '\0';
    printf("%s", result);
    return 0;
}
