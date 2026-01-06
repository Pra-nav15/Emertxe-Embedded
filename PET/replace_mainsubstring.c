#include <stdio.h>

int main()
{
    char str[100], replace[100], newstr[100];
    int i, j, k;

    printf("Enter the Main String : ");
    scanf("%[^\n]", str);

    printf("Enter the String to replace : ");
    scanf(" %[^\n]", replace);

    printf("Enter the new sub string : ");
    scanf(" %[^\n]", newstr);

    int len1 = 0, len2 = 0, len3 = 0;
    while (str[len1]) len1++;
    while (replace[len2]) len2++;
    while (newstr[len3]) len3++;
    if (len2 != len3)
    {
        printf("Replace cannot be possible\n");
        return 0;
    }
    for (i = 0; i <= len1 - len2; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str[i + j] != replace[j])
                break;
        }
        if (j == len2) 
        {
            for (k = 0; k < len3; k++)
                str[i + k] = newstr[k];
        }
    }

    printf("New string is %s\n", str);
    return 0;
}
