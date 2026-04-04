#include <stdio.h>
#include <string.h>
int main()
{
    char str1[200];
    char str2[200];
    char str3[200];
    scanf("%s", str1);
    scanf("%s", str3);
    int i = 0, j = 0;
    while (str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    while (str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    printf("%s", str1);
    int len1 = strlen(str1);
    int len2 = strlen(str3);
    int count = 0;
    int k = 0;
    for (int i = 0;i < len1;i++)
    {
        for (int j = i;j < len2;j++)
        {
            if (str1[i] == str3[j] && str1[i+1] == str3[j+1])
            {
                count++;
            }
        }
    }
    if (count != len2)
    {
        printf("No rotation\n");
    }
    else
    {
        printf("rotation\n");
    }
    return 0;
}