#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d", &n);

    int len[n];
    char** str = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        str[i] = malloc(100);
        printf("Enter string: ");
        scanf("%s", str[i]);
        printf("\n");
    }
    char temp[100];
    for (int i = 0;i < n;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            if (strlen(str[i]) > strlen(str[j]))
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s", str[i]);
        printf("\n");
    }
    return 0;
}